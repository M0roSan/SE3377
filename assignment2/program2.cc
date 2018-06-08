/*Masahiro Yoshida
  SE3377.002*/

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>    //to use transform toupper and tolower
#include "program2.h"

using namespace std;

int main(int argc, char **argv){
  //parse the argument
  parseArg(argc, argv);
  //default value such as -v, -h, -- are handled automatically
  
  //-u and -l are mutually exclusive
  if(optionMap[UPPER] == "true" && optionMap[LOWER] == "true"){
    cout << "Cannot use -u(--upper) and -l(--lower) at the same time" << endl;
    return 0;
  }

  ifstream myInputFile;
  ofstream myOutputFile;
  
  string line;
  int i;
  myInputFile.open(optionMap[INFILE].c_str(), ios::in);
  myOutputFile.open(optionMap[OUTFILE].c_str(), ios::out);
  if(myInputFile.is_open()){
    while(!myInputFile.eof()&&getline(myInputFile, line)){
      i=0;
      if(optionMap[UPPER]=="true"){
	while(line[i]){
	  myOutputFile.put(toupper(line[i]));
	  i++;
	}
      }
      else if(optionMap[LOWER]=="true"){
	while(line[i]){
	  myOutputFile.put(tolower(line[i]));
	  i++;
	}
      }
      else{
	while(line[i]){
	  myOutputFile.put(line[i]);
	  i++;
	}
      }
    }
  }
  myInputFile.close();

  return 0;
}

