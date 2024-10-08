#include <stdio.h>

/*
    논리 연산자: !, &&, ||

    '&' -> 비트 연산자: 정확한 연산 결과를 제공해야하므로 모든 식을 계산 해야한다.
    '&&' -> 논리 곱 연산자: 논리 결과에 따라 0, 1만 반환하면 되기에 SEC를 사용 할 수 있다. (Short Circuit Evaluation)

    1. '&' 비트 연산자 사용
    1-1: 31(0001 1111) & 15(0000 1111) = 15(0000 1111)
    1-2: 30(0001 1110) & 20(0001 0100) = 0001 0100
    1-3: 30(0001 1110) & 1(0000 0001) = 0000 0000

    2. '&&' 논리 곱 연산자 사용
    -> 31(0001 1111) != 15(0000 1111) = 0
 */
int main() {
    int a = 31, b = 15;
    int c = 30, d = 1;
    printf("a & b : %d \n", a & b); // 15
    printf("b & a : %d \n", b & a); // 15
    printf("c & d : %d \n", c & d); // 0

    printf("a >= d : %d \n", a >= d); // 1
    printf("a <= d : %d \n", a <= d); // 0

    printf("a >= d & a <= d : %d \n", a <= d & a >= d & a >= d ); // 0과 1과 1.. 모두 비트 연산 한다. 0 & 1 & 1 = 0
    printf("a >= d & a <= d : %d \n", a <= d && a >= d ); // 연산 결과가 0이면 다음 연산을 실행하지 않고 0을 반환한다.
}