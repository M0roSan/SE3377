/*Masahiro Yoshida
  SE3377.002 */

//parse command line

#include <iostream>
#include <string>
#include <tclap/CmdLine.h>
#include "program5.h"
#include <map>

using namespace std;

map<int, string> optionMap;

void parseArg(int argc, char** argv){

  try{
    TCLAP::CmdLine cmd("SE3377dirmond Directory Monitor Daemon", ' ', "1.0.0");

    //define a switch argument for deaemon mode
    TCLAP::SwitchArg DaemonMode("d", "daemon", "Run in daemon mode (forks to run as a daemon)", cmd, false);

    //define an unlabeled value argument that takes input
    //3rd argument: set to optional
    TCLAP::UnlabeledValueArg<string> configFile("configfile", "The name of the configuration file. Defaults to SE3377dirmond.conf", false,"SE3377dirmond.conf", "config filename", false);

    cmd.add(configFile);

    cmd.parse(argc, argv);
    optionMap[DAEMON] = DaemonMode.getValue()? "true": "false";
    optionMap[CONFIGFILENAME] = configFile.getValue(); 
  }catch(TCLAP::ArgException &e){
    cerr<< "Error: " << e.error() << " happened at " << e.argId() << endl;
  }

}
