#include <stdio.h>
#define PI 3.14159

int main() {
    float r = 5;
    float area = PI * r * r;
    printf("Area = %.2f\n", area);
    return 0;
}
gcc macro_no_arg.c -o macro_no_arg
./macro_no_arg
