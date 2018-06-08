/*Masahiro Yoshida
  SE3377.002*/

#include "program5.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN    (1024 * (EVENT_SIZE + 16))

using namespace std;

void inotifyFunc(){
  const char* path = optionMap[WATCHDIR].c_str(); 
  string pathToVer = optionMap[WATCHDIR] + "/.versions/";
  string mkdir_cmd = "mkdir -p " + pathToVer;
  
  //CREATE SUBFOLDER .VERSIONS
  int dir_err = system(mkdir_cmd.c_str());
  if(dir_err == -1){
    logfile << "Error while creating directory" << endl;
    exit(0);
  }

  //inotify
  int fd, wd;
  fd = inotify_init(); //save its result 
  if(fd  < 0)
    perror("Error at inotify_init()");
  wd = inotify_add_watch(fd, path, IN_MODIFY);
  if(wd < 0)
    perror("Error at inotify_add_watch");

  int length, i = 0;
  char buf[BUF_LEN];
  length = read(fd, buf, BUF_LEN);
  while(i < length){
    struct inotify_event *event;
    event = (struct inotify_event *) &buf[i];
    if(event->len){
      if(event->mask & IN_MODIFY){
	//generate data stamp file names
	int  date = system("date +'%Y.%m.%d-%H:%M:%S'");
	ostringstream convert;
	convert << date;
	//if verbose option is true, log more messages
	if(optionMap[VERBOSE] == "true"){
	  logfile << "Printing something because verbose flag is true" << endl;
	}
	//copy files to the .versions folder
	string new_path = mkdir_cmd + convert.str();
	ofstream file(new_path.c_str());
	file.close();
      }
    }
    i += EVENT_SIZE + event->len;
  }

  (void) inotify_rm_watch(fd, wd);
  (void) close(fd);

}
