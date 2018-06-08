//Masahiro Yoshida

//read binary file and use CDK window

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdint.h>
#include <cstring>
#include "cdk.h"

#define MATRIX_WIDTH 3
#define MATRIX_HEIGHT 5
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

class BinaryFileHeader{

public:
  uint32_t magicNumber;
  uint32_t versionNumber;
  uint64_t numRecords;
};

//records in the file have a fixed length buffer that will hold a c_style string
const int maxRecordStringLength = 25;
class BinaryFileRecord{

public:
  uint8_t strLength;
  char stringBuffer[maxRecordStringLength];
};

int main(){

  WINDOW *window;
  CDKSCREEN *cdkscreen;
  CDKMATRIX *myMatrix;

  const char *rowTitles[] = {"R0","R1","R2","R3","R4","R5"};
  const char *columnTitles[] = {"C0","C1","C2","C3"};
  int boxWidths[] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int boxTypes[] = {vMIXED, vMIXED, vMIXED, vMIXED, vMIXED, vMIXED};

  //initialize the cdk screen
  window = initscr();
  cdkscreen = initCDKScreen(window);

  //start CDK colors
  initCDKColor();

  //create the matrix
  //need to manually cast (const char**) to (char**)
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_NAME_STRING, 
			  (char **) rowTitles, (char**) columnTitles, boxWidths, boxTypes, 1, 1, ' ', ROW, true, true, false);

  if(myMatrix == NULL){
    printf("Error creating Matrix\n");
    _exit(1);
  }

  //Display the Matrix
  drawCDKMatrix(myMatrix, true);

  //---------------------------------------------------
  //read binary file and map them in the cdk display
  
  BinaryFileHeader *myHeader = new BinaryFileHeader();
  
  ifstream binInHeader("cs3377.bin", ios::in | ios::binary);

  if(!binInHeader){
    printf("Error opening a binary file");
    _exit(1);
  }
  
  
  string out;
  stringstream convert;
  
  binInHeader.read((char*) myHeader, sizeof(BinaryFileHeader));
  
  convert << "0x" << hex << myHeader->magicNumber; //convert unsigned to hex string
  out = convert.str();
  setCDKMatrixCell(myMatrix, 1, 1, out.c_str()); // display

  convert.str(""); //clean the content
  convert << "Version: " << dec << myHeader->versionNumber;
  out = convert.str();
  setCDKMatrixCell(myMatrix, 1, 2, out.c_str());

  convert.str("");
  convert << "NumRecords: " << myHeader->numRecords;
  out = convert.str();
  setCDKMatrixCell(myMatrix, 1, 3, out.c_str());

  long int pos = sizeof(BinaryFileHeader); //get the size of myHeader
  BinaryFileRecord *myRecord = new BinaryFileRecord();

  ifstream binInRecord("cs3377.bin", ios::in | ios::binary);

  if(!binInRecord){
    printf("Error opening a binary file");
    _exit(1);
  }
  binInRecord.seekg(pos); //move the cursor
  
  for(int i = 2; i <= MATRIX_HEIGHT; i++){
    if(!binInRecord.eof()){
      binInRecord.read((char*) myRecord, sizeof(BinaryFileRecord));
      convert.str("");
      convert << "strlen: " << strlen(myRecord->stringBuffer);
      out = convert.str();
      setCDKMatrixCell(myMatrix, i, 1, out.c_str());
      setCDKMatrixCell(myMatrix, i, 2, myRecord->stringBuffer);
    }
  }

  //Display a message
  drawCDKMatrix(myMatrix, true); //required


  //----------------------------------------------

  //to see results
  unsigned char x;
  cin >> x;

  //clean up screen
  endCDK();

  return 0;
}
