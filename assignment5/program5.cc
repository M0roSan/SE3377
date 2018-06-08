/*Masahiro Yoshida
  SE3377.002 */

//main function

#include <iostream> 
#include <map>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <csignal>
#include "program5.h"

using namespace std;

ofstream logfile;
ofstream pidfile;

int main(int argc, char** argv){
  //parse the argument
  parseArg(argc, argv);
  //parse the config file  
  parseConf(0);
  if(optionMap[DAEMON] == "true"){
    processControlFunc();
  }  
  return 0;
}
