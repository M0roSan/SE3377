/*Masahiro Yoshida
 *SE3377.002
 */

%option noyywrap
%option nounput
%option noinput

%{
 #include <stdlib.h>
 #include "y.tab.h"
%}

%%
[ \t]+       {/*eat up white space*/}
[\r\n]         { return EOLTOKEN;}
"#"          { return HASHTOKEN;}
"-"          { return DASHTOKEN;}
","          { return COMMATOKEN;}
[Jj][Rr]\.?  { yylval.str = strdup(yytext); return JRTOKEN;}
[Ss][Rr]\.?  { yylval.str = strdup(yytext); return SRTOKEN;}
V?I{0,3}     { yylval.str = strdup(yytext); return ROMANTOKEN;}  //cover 1-3 and 5-8
IV           { yylval.str = strdup(yytext); return ROMANTOKEN;}  //cover 4
IX           { yylval.str = strdup(yytext); return ROMANTOKEN;}  //cover 9
[0-9]+       { yylval.value = atoi (yytext); return INTTOKEN;}  //integer
[a-zA-Z]\.?   { yylval.str = strdup (yytext); return NAME_INITIAL_TOKEN;}
[a-zA-Z]{2,} { yylval.str = strdup(yytext); return NAMETOKEN;}
[a-zA-Z0-9]+ { yylval.str = strdup(yytext); return IDENTIFIERTOKEN;}

%%
