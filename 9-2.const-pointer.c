#include <stdio.h>
int main() {
    int a;
    int b;
    const int* pa = &a; // (1) int 자료형에 저장된 값을 수정하지마!
    int* const pb = &b; // (2) pa 변수에 저장된 값을 수정하지마!

    //*pa = 3;
    //pa = &b;
    printf("%p \n", pa);
}