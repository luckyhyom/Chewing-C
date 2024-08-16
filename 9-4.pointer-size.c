#include <stdio.h>
int main() {
    int a;
    int arr[6];
    int* parr = &arr[0];

    /* 
        배열의 변수 이름은 배열의 첫번째 요소의 주소를 출력한다.
        이유는, 암묵적으로 그렇게 정해졌기 때문
    */
    printf("arr : %p \n", arr);
    printf("parr : %p \n", parr); // 배열의 첫번째 요소의 주소

    /* 하지만, 변수 이름이 첫번째 요소에 대한 포인터는 아니다. */
    printf("sizeof int a : %d \n", sizeof a); // 4 byte
    printf("sizeof arr : %d \n", sizeof arr); // 24 byte (4*6) -> 배열의 정의된 크기를 출력한다.
    printf("sizeof parr : %d \n", sizeof parr); // 8 byte (int 자료형의 크기가 아닌 주소값의 크기)
    return 0;
}