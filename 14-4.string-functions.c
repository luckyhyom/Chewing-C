#include <stdio.h>

int copy(char *str_ori, char *str_copy);
int concat(char *str_ori, char *str_copy1, char *str_copy2);

int main() {
    char str[10] = "hello!";
    char str2[10];
    copy(str2, str);
    printf("%s \n", str2);

    char result[50];
    char copy1[] = "Hello ";
    char copy2[] = "World";
    concat(result, copy1, copy2);
    printf("%s \n", result);
    return 0;
}


/*
    1. 지역 배열은 함수가 종료되면 메모리에서 제거된다. (지역 배열은 반환이 불가능하다.)
 */
int copy(char *str_ori, char *str_copy) {
    //int i=0;
    //while (str_copy[i])
    //{
    //    str_ori[i] = str_copy[i];
    //    i++;
    //}

    // 포인터 연산을 활용하기
    while (*str_copy)
    {
        *str_ori = *str_copy;
        str_ori++;
        str_copy++;
    }
    
    return 0;
}

int concat(char *str_ori, char *str_copy1, char *str_copy2) {
    int ori_idx = 0;

    int i=0;
    while (str_copy1[i])
    {
        str_ori[ori_idx] = str_copy1[i];
        i++;
        ori_idx++;
    }

    i=0;
    while (str_copy2[i])
    {
        str_ori[ori_idx] = str_copy2[i];
        i++;
        ori_idx++;
    }

    return 0;
}