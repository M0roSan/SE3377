/*Masahiro Yoshida
 *SE3377.002
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"

//global 
int yylex(void);
int yyparse(void);

int main(int argc, char **argv){
  //change the behavior by the argument 0, either scanner or parser
  char *SCANNER = "./scanner";
  char *argv0 = argv[0];
  if(strcmp(SCANNER, argv0) == 0){
    int token;
    token = yylex();
    printf("Operating in scanner mode\n\n");
    //while not EOF, call yylex
    while(token != 0){
      
      printf("yylex returned ");
      
      switch(token){
      case NAME_INITIAL_TOKEN:
	printf("NAME_INITIAL_TOKEN token (%s)\n", yylval.str);
	break;
      case NAMETOKEN:
	printf("NAMETOKEN token (%s)\n", yylval.str);
	break;
      case EOLTOKEN:
	printf("EOLTOKEN token (%d)\n", token);
	break;
      case INTTOKEN:
	printf("INTTOKEN token (%d)\n", yylval.value);
	break;
      case HASHTOKEN:
	printf("HASHTOKEN token (%d)\n", token);
	break;
      case COMMATOKEN:
	printf("COMMATOKEN token (%d)\n", token);
	break;
      case DASHTOKEN:
	printf("DASHTOKEN token (%d)\n", token);
	break;
      case ROMANTOKEN:
	printf("ROMANTOKEN token (%d)\n", token);
	break;
      case SRTOKEN:
	printf("SRTOKEN token (%d)\n", token);
	break;
      case JRTOKEN:
	printf("JRTOKEN token (%d)\n", token);
	break;
      case IDENTIFIERTOKEN:
	printf("IDENTIFIERTOKEN token (%s)\n", yylval.str);
	break;
      default: 
	printf("something unexpected happened");
	break;
      }

      //update token to next word
      token = yylex();

    }
    printf("\nScan success\n");
    return 0;
  }
  else/* parser or regular behavior of the program*/{
    //call yyparse once, it will call yylex recursively until EOF
    printf("Operating in parse mode\n\n");

    switch(yyparse()){
    case 0:
      printf("\nParse success\n");
      break;
    case 1:
      printf("Parse fail\n");
      break;
    case 2: 
      printf("Error with memory\n");
      break;
    default: 
      printf("Unexpeced error from yyparse()\n");
      break;
    }
  }
  return 0;
}

