/*Masahiro Yoshida
  SE3377.002 */

#include <string> 
#include <map>
#include <iostream>
#include <fstream>

using namespace std;

#ifndef LOGFILE_H
#define LOGFILE_H
extern ofstream logfile;
#endif

#ifndef PIDFILE_H
#define PIDFILE_H
extern ofstream pidfile;
#endif


extern map<int, string> optionMap;
void parseArg(int, char**);
void parseConf(int mode);
void logging();
void childProcess();
void parentProcess();
void signalHandler(int signum);
void inotifyFunc();
void processControlFunc();
enum tclapKey{DAEMON, CONFIGFILENAME, VERBOSE, LOGFILE, PASSWORD, NUMVERSIONS, WATCHDIR};
