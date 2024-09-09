#include <stdio.h>
#include <string.h>
#define VAR 2
#define A
//#define B
#define Calculator_Type_A

int main() {
    char a[20] = "hanni";
    char b[20] = "haerin";
    printf("%c \n", a[VAR]);

    #ifdef A // ifdef에서 지정한 매크로가 지정되어있다면 실행된다.
        printf("AAAA \n");
    #endif

    #ifdef B
        printf("BBBB \n");
    #endif

    #ifdef Calculator_Type_A
        float var1, var2;
    #endif

    #ifdef
        double var1, var2;
    #endif

    {
        var1 + var2;
    }

    return 0;
}