#include <stdio.h>
#include <string.h>

char prod[10][10];
char first[10], follow[10];
int n, m = 0, f = 0;

void FIRST(char c);
void FOLLOW(char c);

int main() {
    int i;
    char c, ch;

    printf("Enter number of productions: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        printf("Production %d: ", i + 1);
        scanf("%s", prod[i]);
    }

    printf("Enter symbol to compute FIRST and FOLLOW: ");
    scanf(" %c", &c);

    printf("FIRST(%c) = { ", c);
    FIRST(c);
    for(i = 0; i < m; i++) printf("%c ", first[i]);
    printf("}\n");

    printf("FOLLOW(%c) = { ", c);
    FOLLOW(c);
    for(i = 0; i < f; i++) printf("%c ", follow[i]);
    printf("}\n");

    return 0;
}

void FIRST(char c) {
    int i;
    if(!(c >= 'A' && c <= 'Z')) {
        first[m++] = c;
    } else {
        for(i = 0; i < n; i++) {
            if(prod[i][0] == c) {
                if(prod[i][2] == '$') {
                    FIRST(prod[i][0]);
                } else if(!(prod[i][2] >= 'A' && prod[i][2] <= 'Z')) {
                    first[m++] = prod[i][2];
                } else {
                    FIRST(prod[i][2]);
                }
            }
        }
    }
}

void FOLLOW(char c) {
    int i, j;
    if(prod[0][0] == c) follow[f++] = '$';
    for(i = 0; i < n; i++) {
        for(j = 2; j < strlen(prod[i]); j++) {
            if(prod[i][j] == c) {
                if(prod[i][j+1] != '\0') {
                    FIRST(prod[i][j+1]);
                    for(int k = 0; k < m; k++)
                        if(first[k] != '$') follow[f++] = first[k];
                }
                if(prod[i][j+1] == '\0' && prod[i][0] != c)
                    FOLLOW(prod[i][0]);
            }
        }
    }
}


gcc first_follow.c -o first_follow
./first_follow
