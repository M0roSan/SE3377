#Masahiro Yoshida
#SE3377.002

CXX=g++
CXXFLAGS=-Wall
CPPFLAGS = 
SRCS = file1.cc file2.cc

OBJS = $(SRCS:.cc=.o)

#override the implicit rule for .o
%o:%cc
	$(CXX) -c $(CXXFLAGS)$(CPPFLAGS) -O $< -o $@

all:myHW3

clean:
	rm -f *.o myHW3

myHW3:$(OBJS)
	$(CXX) -o $@ $(OBJS)
