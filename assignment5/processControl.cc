/*Masahiro Yoshida
  SE3377.002 */

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <csignal>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include "program5.h"

void processControlFunc(){
  //run as daemon
  logging(); // to open logfile
  if(logfile.is_open() == false){
    printf("Cannot open %s\n", optionMap[CONFIGFILENAME].c_str());
    exit(0);
  }else{
    printf("Reading %s\n", optionMap[CONFIGFILENAME].c_str());
  }
  if(pidfile.is_open()){
    logfile << "Error: SE3377dirmond.pid exists, it shouldn't have existed. Deleting the file and exiting from daemon\n" << endl;
    pidfile.close();
    remove("SE3377dirmond.pid");
    exit(0);
  }
  string pidfilename = "SE3377dirmond.pid";
  signal(SIGINT, signalHandler);
  signal(SIGHUP, signalHandler);
  signal(SIGTERM, signalHandler);
  pidfile.open(pidfilename.c_str());
  pid_t forkvalue = fork();
  if(forkvalue == -1){
    perror("There was an error in the fork\n");
    exit(0);
  }
  else if(forkvalue == 0){
    logfile << "this is child" << endl;
    pidfile << forkvalue << endl;
    //call other function
    //like watch dir
    // or update config file
    inotifyFunc();
    sleep(10000);
  }
  else{
    logfile << "this is the parent" << endl;
    pidfile << forkvalue << endl;
    
    sleep(10000);

  }

}
