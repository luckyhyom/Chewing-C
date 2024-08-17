#include <stdio.h>

int main() {
    int a = 777;
    int *pa;
    int **ppa;

    pa = &a;
    ppa = &pa;

    printf("a : %d \n", a);
    printf("*pa : %d \n", *pa); // a의 메모리 주소에 있는 값

    printf("&pa : %p \n", &pa);
    printf("ppa : %p \n", ppa); // ppa = pa의 메모리 주소를 가지고 있다.

    printf("*ppa : %p \n", *ppa); // *ppa = pa가 가지고 있는 값.. a의 주소
    printf("pa : %p \n", pa);
    printf("&a : %p \n", &a);

    printf("**ppa : %d \n", **ppa); // pa의 메모리 주소에 있는 값 = a의 값

    int arr[5] = { 10 ,};
    printf("%p : \n", &arr);
    printf("%p : \n", arr);

    return 0;
}