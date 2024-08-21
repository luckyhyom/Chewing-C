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

    /*
        '*'은 그저 몇번이나 저장된 값을 '주소'로 인식하여 해당 주소의 값을 반환하도록 할 것인지 정의할 뿐이다.
        그렇다면, 포인터를 가리키는 포인터여도 '*'을 한번만 써도 상관없다.
        그저 가진 값을 '주소'로 인식하여 해당 주소의 값을 반환하는 기능을 한번만 쓸 수 있게 되는 것 뿐이다.
        -> 결국 포인터를 가리키는 포인터에 '*'을 한번만 쓰면.. 한번밖에 메모리 주소를 못찾아간다.

        .. 왜 예상과 다른 결과가 나올까?
    */
    int b = 1;
    int *pb = &b;
    int *ppb = &pb;
    printf("b : %d, *pb : %d \n", b, *pb); // **ppb는 컴파일 에러.
    printf("&b : %p, pb : %p, *ppb : %p \n", &b, pb, *ppb); // &b : 0x16d1872a4, pb : 0x16d1872a4, *ppb : 0x6d1872a4
    printf("&pb : %p, ppb : %p \n", &pb, ppb);

    return 0;
}