#include <stdio.h>

// 문자열을 숫자로 변환하는 함수
int string_to_int(const char *str) {
    int result = 0;

    // 문자열을 왼쪽에서 오른쪽으로 순차적으로 읽으며 숫자로 변환
    for (int i = 0; str[i] != '\0'; i++) {
        result = result * 10 + (str[i] - '0');
    }

    return result;
}

// 두 문자열을 숫자로 변환한 후 더한 값을 반환하는 함수
int add_strings(const char *str1, const char *str2) {
    int num1 = string_to_int(str1);
    int num2 = string_to_int(str2);
    return num1 + num2;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("사용법: %s <숫자1> <연산자> <숫자2>\n", argv[0]);
        return 1;
    }


    int result = add_strings(argv[1], argv[3]);
    printf("결과: %d\n", result);

    return 1;
}
