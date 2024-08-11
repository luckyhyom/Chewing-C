/* 산술 연산 */
#include <stdio.h>
int main() {
    int a,b;
    a = 10; // Assignment Operator (대입 연산자)
    b = 3;
    printf("a + b 는 : %d \n", a + b);
    printf("a - b 는 : %d \n", a - b);
    printf("a * b 는 : %d \n", a * b);
    printf("a / b 는 : %d \n", a / b);
    printf("a %% b 는 : %d \n", a % b);

    /* 산술 변환: 작은 자료형이 더 큰 자료형으로 변환된다. */
    int c; // 연산 과정에서 자료형이 double로 변환된다.
    double d;
    c = 10;
    d = 3;
    printf("c / d 는 : %f", c / d);
    return 0;
}