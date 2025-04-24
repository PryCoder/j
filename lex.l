%{
int chars = 0, words = 0, lines = 0, tabs = 0, blanks = 0, sentences = 0, numbers = 0;
%}

%%
[0-9]+          { numbers++; chars += yyleng; }
[ \t]+          { for (int i = 0; i < yyleng; i++) if (yytext[i] == '\t') tabs++; else blanks++; }
\n              { lines++; chars++; }
[.!?]           { sentences++; chars++; }
[a-zA-Z]+       { words++; chars += yyleng; }
.               { chars++; }
%%

int main() {
    yylex();
    printf("Characters: %d\nWords: %d\nLines: %d\nTabs: %d\nSentences: %d\nNumbers: %d\nBlanks: %d\n",
           chars, words, lines, tabs, sentences, numbers, blanks);
    return 0;
}


lex wordcount.l
gcc lex.yy.c -o wordcount -ll
./wordcount < input.txt
