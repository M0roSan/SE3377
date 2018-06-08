#Masahiro Yoshida


#Flags for C++ implicit rules
CXX = g++
CXXFLAGS = 
CPPFLAGS = -Wall

#Flags for the Lex implicit rules
LEX = /usr/bin/flex
LFLAGS = 

#Flags for the Yacc implicit rules
YACC = /usr/bin/bison
YFLAGS = -dy

#PROJECTNAME for backup target 
PROJECTNAME = SE3377.hw4

EXECFILE = program4

#keep the internmediate file 
.PRECIOUS: parse.c scan.c

OBJS = parse.o scan.o program4.o

all: $(EXECFILE)

clean:
	rm -f $(OBJS) $(EXECFILE) y.tab.h *~ \#*
	
$(EXECFILE): $(OBJS)
	$(CXX) -o $@ $(OBJS)
	ln -fs ./$@ scanner
	ln -fs ./$@ parser
backup:
	@make clean
	@mkdir -p ~/backups; chmod 700 ~/backups
	@$(eval CURDIRNAME :=$(shell basename "'pwd'"))
	@$(eval MKBKUPNAME := ~/backups/$(PROJECTNAME)-$(shell date +'%Y.%m.%d-%H.%M.%S').tar.gz)
	@echo
	@echo Writing backup file to: $(MKBKUPNAME)
	@echo
	@-tar zcvf $(MKBKUPNAME) ../$(CURDIRNAME)
	@chmod 600 $(MKBKUPNAME)
	@echo
	@echo DONE!
