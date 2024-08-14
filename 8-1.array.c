#include <stdio.h>

/*
    1. 배열을 한번에 출력할 수 없다니..
    2. 배열의 크기를 알 수 없을 때..
 */
int main() {
    int prime_numbers[1000] = {0, };
    int i, j;

    for (i = 0; i <= 1000; i++)
    {
        if(i%2 == 0) continue; // 짝수면 넘어가고 홀수만 계산한다.
        for (j = 0; j <= 1000; j++)
        {
            if(j > i) break; // 대상 값 이하의 소수만 비교한다. 만약 7의 소수를 구할 때 7과 같거나 7보다 크다면 더 볼 필요가 없으므로 나간다.
            if(j == i) continue; // 같은 값으로 나누는 것은 스킵
            if(j == 1) continue; // 1로 나누는 것은 스킵
            if(j == 0) continue; // 0으로 나누는 것은 스킵

            float prime = (float)i/j;
            int isDecimal = (prime - (int) prime) * 1000;
            if(isDecimal == 0) {    // 나눈 값이 정수인지 판별한다.
                break; // 정수라면 소수가 아니다.
            }

            if(i - 1 == j) { // 한번도 결과 값이 정수가 나오지 않았다면 소수!
                printf("i: %d, j: %d, prime: %f \n", i, j , prime);
            }
        }
    }
}