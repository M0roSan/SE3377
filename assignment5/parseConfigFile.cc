/*Masahiro Yoshida
  SE3377.002 */

#include <iostream>
#include <rude/config.h>
#include "program5.h"
#include <string>
#include <map>

using namespace std;


void parseConf(int mode){
  //create object
  rude::Config config;
  //load a configuration file
  const char* infile = optionMap[CONFIGFILENAME].c_str();
  config.load(infile);
  config.setSection("Parameters");
  string verbose = config.getStringValue("Verbose");
  string logfile = config.getStringValue("LogFile");
  string password = config.getStringValue("Password");
  string numversions = config.getStringValue("Numversions");
  string watchdir = config.getStringValue("WatchDir");

  switch(mode){
  case 0: // read everything
    optionMap[VERBOSE] = verbose;
    optionMap[LOGFILE] = logfile;
    optionMap[PASSWORD] = password;
    optionMap[NUMVERSIONS] = numversions;
    optionMap[WATCHDIR] = watchdir;
    break;

  case 1: // not allowing change on password and watchdir
    optionMap[VERBOSE] = verbose;
    optionMap[LOGFILE] = logfile;
    optionMap[NUMVERSIONS] = numversions;
    break;

  default: 
    break;
  }    
}
