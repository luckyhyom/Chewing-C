#include <stdio.h>

int main()
{
    int sum = 0;
    int power = 1;
    int operator;
    int input_value;
    while (power == 1)
    {
        printf("=> 현재 값 %d \n", sum);

        printf("연산자를 입력하세요. \n (1) 더하기, (2) 빼기 \n");
        scanf("%d", &operator);

        if(operator == 1) {
            printf("더할 값을 입력하세요.");
            scanf("%d", &input_value);
            sum += input_value;
        } else if (operator == 2) {
            printf("뺄 값을 입력하세요.");
            scanf("%d", &input_value);
            sum -= input_value;
        } else {
            printf("잘못된 번호 입니다.");
        }
    }
    return 0;
}
