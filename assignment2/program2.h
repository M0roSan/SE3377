//Masahiro Yoshida
//SE3377.002
#include <string>
#include <map>
#include <iostream>

using namespace std;

//define a map globally
extern map<int, string> optionMap;
void parseArg(int, char**);

enum tclapKey{INFILE, LOWER, UPPER, OUTFILE};
