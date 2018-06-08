#Masahiro Yoshida
#SE3377.002


#Flags for C++ implicit rules
CXX = g++
CXXFLAGS = 
CPPFLAGS = -Wall

#Define any directories containing header files
IFLAGS = -I/home/010/m/mx/mxy172130/include

#Define library path
LDFLAGS = -L/home/010/m/mx/mxy172130/lib

#Define any libraries to link into executable
LDLIBS = -lrudeconfig

#PROJECTNAME for backup target 
PROJECTNAME = SE3377.hw5

EXECFILE = program5

SRCS = parseCommandLine.cc parseConfigFile.cc loggingFunctions.cc signalHandling.cc inotifyFunctions.cc processControl.cc program5.cc

OBJS = $(SRCS:cc=o)

all: $(EXECFILE)

clean:
	rm -f $(OBJS) *~ \#*

#static link
$(EXECFILE): $(SRCS)
	$(CXX) -static -o $(EXECFILE) $(SRCS) $(IFLAGS) $(LDFLAGS) $(LDLIBS)

backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME := $(shell pwd))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H.%M.%S').tar.gz)
	@echo
	@echo Writing backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcvf $(MKBKUPNAME) $(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo DONE!
