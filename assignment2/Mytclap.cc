// Masahiro Yoshida
// SE3377.002
#include <iostream>
#include <string>
#include <tclap/CmdLine.h>
#include "program2.h"
#include <map>

using namespace std;
map<int, string> optionMap;

void parseArg(int argc, char** argv){

  try{
    TCLAP::CmdLine cmd("Command description", ' ', "1.0.0");
    
    //Define a switch argument that converts all text to lowercase
    //5th argument: set false as default
    TCLAP::SwitchArg makeLower("l", "lower", "Convert all text to lowercase", cmd, false);
    
    //Define a switch argumetn that converts all text to uppercase
    //5th argument: set false as default
    TCLAP::SwitchArg makeUpper("u", "upper", "Convert all text ot uppercase", cmd, false);

    //Define a value argument that chagnes the output file
    //4th argument: this argument is not required
    //5th argument: default name is "output.txt"
    TCLAP::ValueArg<string> outputFile("o", "outfile",
				       "The name of the output file", false, "output.txt",
				       "output filename");
    
    //add outputFile to the command line
    cmd.add(outputFile);

    //Define an unlabeled  value argument that takes input, required
    //set to the last argument
    //3rd argument: required
    TCLAP::UnlabeledValueArg<string> inputFile("infile", "Input file", true, "infile.txt",
					       "input filename", false);
    cmd.add(inputFile);
    
    // parse the argv array
    cmd.parse(argc, argv);
    optionMap[INFILE] = inputFile.getValue();
    optionMap[OUTFILE] = outputFile.getValue();
    if(makeUpper.getValue())
      optionMap[UPPER] = "true";
    else 
      optionMap[UPPER] = "false";
    
    if(makeLower.getValue())
      optionMap[LOWER] = "true";
    else 
      optionMap[LOWER] = "false";
  }catch(TCLAP::ArgException &e) // catch exceptions
    { cerr << "error: " << e.error() << " happened at " << e.argId() << endl;}
}
