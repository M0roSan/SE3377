/* Masahiro Yoshida
   SE3377.002*/
/* display a log message that states you're inside the procedure.
   this log message must be sent to stderr*/
#include <iostream> 

using namespace std;

int proc1(){
  cerr << "Inside proc1() as stderr" << endl;
  return 0;
}
