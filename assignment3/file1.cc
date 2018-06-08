//Masahiro Yoshida
//SE3377.002

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file.h"

using namespace std;

#define BUFFER_SIZE 1024

int main(int argc, char **argv){
  func(); //this will do nothing, just included to show using of Makefie
  FILE *output_from_command1;
  FILE *output_from_command2;
  char tmpbuffer[BUFFER_SIZE];
  char* line_p1;
  char* line_p2;

  //c++ string object
  string Shellcmd = "/home/010/m/mx/hw/hw3/bin/gawk";
  string Shellcmd1 = "/home/010/m/mx/mxy172130/hw/hw3/bin/gawk --version";
  string Shellcmd2 = "/home/010/m/mx/hw/hw3/bin/gawk -f gawk.code numbers.txt";

  cout << "gawk at: " << Shellcmd << endl;
  cout << "Shellcmd1: " << Shellcmd1 << endl;
  cout << "Shellcmd2: " << Shellcmd2 << endl;

  //execute the Shellcmd1 to print out verision
  output_from_command1 = popen(Shellcmd1.c_str(), "r");

  //if not opened, error out
  if(!output_from_command1)
    return -1;

  cout << endl;
  cout << "The first call to gawk returned: " << endl;
  cout << endl;

  //read at most BUFFER_SIZE butes from file and store in tempbuffer. returns NULL on EOF
  line_p1 = fgets(tmpbuffer, BUFFER_SIZE, output_from_command1);

  while(line_p1 != NULL){
    cout << line_p1;
    line_p1 = fgets(tmpbuffer, BUFFER_SIZE, output_from_command1);
  }
  
  //close output_from_command1
  pclose(output_from_command1);

  
  //execute shell command
  output_from_command2 = popen(Shellcmd2.c_str(), "r");

  if(!output_from_command2)
    return -1;

  cout << endl;
  cout << "The second call to gawk returned: ";
  
  line_p2 = fgets(tmpbuffer, BUFFER_SIZE, output_from_command2);
  cout << line_p2;
  
  int intArray[2];
  int counter = 0;
  char* tok = strtok(line_p2, " ");
  while(tok){
    intArray[counter++] = atoi(tok);
    tok = strtok(NULL, " ");
  }

  cout << endl;
  cout << "The sum of Columns 1 is: " << intArray[0] << endl;
  cout << "The sum of Columns 2 is: " << intArray[1] << endl;
  cout << "The sum of the two numbers is: " << intArray[0] + intArray[1] << endl;

  pclose(output_from_command2);
  cout << endl << endl;

  return 0;
  
}
