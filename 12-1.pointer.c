#include <stdio.h>

int main() {
    /*
        주소값 연산자에서는 arr이 int형 포인터로 변환되지 않는다.
        따라서 parr은 int 자료형 3개 크기의 배열을 가리키는 포인터가 됨.
    */
    int arr[3] = {1,2,3};

    int (*parr)[3] = &arr; // int 자료형 [3]크기 배열의 포인터가 필요하다.
    printf("(*parr)[1] : %d \n", (*parr)[1]); // arr은 사실 메모리에 존재하지 않는다. 따라서 &arr[0] 주소의 값이 나온다.

    int *parr2 = arr; // &arr[0]의 주소를 저장 (arr = 원소 1에 대한 주소)
    printf("parr2[1] : %d \n", parr2[1]);
    printf("parr2[1] : %d \n", *parr2);

    /*
        barr = &barr[0]
            (barr => barr[0] => barr[0][0])
        결국에는 피연산자의 자료형에 맞춰서 포인터를 선언해야한다는 것이다.
    */
    int barr[2][3] = {{1,2,3},{4,5,6}};
    //int *pbarr = barr; // &barr[0]을 int자료형 만큼 읽어들이기 때문에.. 
    int (*pbarr)[3] = barr; // &barr[0]을 int자료형 만큼 읽어들이기 때문에.. 
    printf("%d \n", pbarr[0][2]);


    return 0;
}