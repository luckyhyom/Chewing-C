#include <stdio.h>

/*
    1. str[]은 배열이기 때문에 값 수정이 가능
    2. pstr은 literal (고정 값)이기 때문에 수정 불가능 (메모리 구조에서 readonly segment에 저장되어있음)
*/
int main() {
    char str[] = "sentence"; // char[size]
    char *pstr = "sentence"; // -> *pstr = &(char)[0]

    str[1] = 'a';
    //pstr[1] = 'b';
    printf("str : %s \n", str);
    printf("pstr : %s \n", pstr);
    return 0;
}