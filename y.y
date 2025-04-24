%{
#include <stdio.h>
#include <stdlib.h>
%}

%token NUM
%left '+' '-'
%left '*' '/'

%%
expr: expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'
    | NUM
    ;
%%

int main() {
    printf("Enter expression: ");
    yyparse();
    printf("Valid expression!\n");
    return 0;
}

int yyerror(char *msg) {
    printf("Invalid expression.\n");
    return 1;
}
yacc -d expr.y
lex expr.l
gcc y.tab.c lex.yy.c -o expr
./expr
