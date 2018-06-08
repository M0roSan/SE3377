/* Masahiro Yoshida
   SE3377.002
 */
/* main()routine,count of command line arguments to stdout
further display the value of each command line argument to stdout
finally call the procedure that is defined in the second file*/
#include <iostream>
#include "file12.h"

using namespace std;
// argc is to count numbre of arguments
// argv is to point name of argument
int main(int argc, char* argv[]){
  cout << "args was: " << argc << endl;
  for(int i = 0; i < argc; i++){
    cout <<  argv[i] << endl;
  }
  proc1();
  return 0;
} 
