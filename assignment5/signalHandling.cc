/*Masahiro Yoshida
  SE3377.002 */

//signal handling

#include <csignal>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include "program5.h"

using namespace std;

void signalHandler(int signum){
  switch(signum){
  case SIGTERM:
  case SIGINT:
    logfile << "received signal SIGINT. closing logfile and removing pidfile" << endl; 
    //close logfile
    logfile.close();
    //close pidfile and remove it
    pidfile.close();
     remove("SE3377dirmond.pid");
    exit(signum);
    break;
  case SIGHUP:
    logfile << "received signal SIGHUP. updating map of config" << endl;
    parseConf(1); //renew map of conf file, mode 1(not password nor watchdir)
    break;
  default:
    cout << "do nothing here" << endl;
    break;
  }
}
