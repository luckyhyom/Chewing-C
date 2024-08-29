#include <stdio.h>

int main() {
    int num;
    char c;
    char ch;

    printf("숫자를 입력 : \n");
    scanf("%d", &num);

    ch = getchar();
    printf("getchar() :==%c== \n", ch);

    printf("문자를 입력 : \n");
    scanf("%c", &c);

    printf("%d, %c \n", num, c);
    return 0;
}