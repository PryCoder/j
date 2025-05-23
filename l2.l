%{
#include "y.tab.h"
%}

%%
[0-9]+        { yylval = atoi(yytext); return NUM; }
[+\-*/()]     { return *yytext; }
[ \t\n]       ;  // skip whitespace
.             { return yytext[0]; }
%%

int yywrap() { return 1; }
