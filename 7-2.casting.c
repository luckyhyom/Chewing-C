#include <stdio.h>
int main() {
    int i;
    float f;
    printf("실수를 입력하시오 : ");
    scanf("%f", &f);
    i = (f - (int)f) * 100; // 입력한 실수의 소수점 둘째자리까지를 정수로 표현하기.
    printf("i=%d\n", i);
    return 0;
}