#include <stdio.h>
int main() {
    int *p;
    int a;
    p = &a;
    *p = 2;
    printf("%d \n", a);
    printf("%d \n", *p);
    return 0;
}