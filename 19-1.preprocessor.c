/*
    전처리기 명렁 (e.g. #include 따위)
    1. 컴파일 이전에 실행된다.
    2. 지칭된 파일의 내용을 모두 복사해온다.
    3. Angle Bracket (<>)은 컴파일러에서 지원하는 헤더 파일
    4. Double Quotation Marks("")는 사용자가 직접 추가한 파일

    헤더 파일
    1. 링킹을 위한 파일
    2. 보통 소스파일의 이름을 따서 만든다. (src.c -> src.h)
*/
#include <stdio.h>
#include "19-3.string.h"

int main() {
    char str1[20] = "ABCD";
    char str2[20] = "ABCD";

    printf("문자열 A : ");
    scanf("%s", str1);
    printf("문자열 B : ");
    scanf("%s", str2);

    if (compare(str1, str2)) {
        printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
    } else {
        printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
    }
    return 0;
}


char compare(char *str1, char *str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++; 
    }
    if (*str2 == '\0') return 1;
    return 0;
}
