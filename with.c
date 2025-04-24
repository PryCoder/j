#include <stdio.h>
#define SQUARE(x) ((x) * (x))

int main() {
    int num = 4;
    int result = SQUARE(num);
    printf("Square = %d\n", result);
    return 0;
}
gcc macro_with_arg.c -o macro_with_arg
./macro_with_arg
