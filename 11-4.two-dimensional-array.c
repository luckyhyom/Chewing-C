#include <stdio.h>

/*
    sizeof arr = 24로써 전체 크기가 나오지만, 가장 바깥을 감싸는 것을 가리키는 포인터는 없다.
    arr은 첫번째 행의 포인터다.

    1) int arr[2]; 배열이 정의되었을 때
    1-1) arr = arr[0]을 가리키는 포인터 (int 자료형을 가리키는 포인터)

    2) int arr[2][2]; 배열이 정의되었을 때
    2-1) arr[0] = arr[0][0]을 가리키는 포인터 (int 자료형을 가리키는 포인터)
    2-2) arr[1] = arr[1][0]을 가리키는 포인터 (int 자료형을 가리키는 포인터)
    2-3) arr = int 자료형을 가리키는 포인터를 가리키는 포인터 + int[2] 자료형을 가리키는 포인터
        *arr = 첫번째 행
        **arr = 첫번째 행의 첫번째 원소
 */
int main() {
    //int barr[3] = {1,2,3};
    //int *pbarr = barr;
    //printf("%d", pbarr[1]); // int 자료형을 가리키는 포인터다. 따라서 4바이트 만큼 한칸 이동한다.

    int arr[2][3] = {{1,2,3},{4,5,6}};
    //printf("**arr : %d \n", **arr); // 1
    //printf("**arr : %d \n", *(*arr+1)); // 2 (*arr의 주소는 1) int 자료형을 가리키는 포인터
    //printf("**arr : %d \n", **(arr+1)); // 4 (arr의 주소는 첫번째 행).. 배열크기[3]을 가리키는 포인터

    int *parr;
    parr = arr;
    printf("parr[1][1] : %d \n", *(parr + 1)); // arr의 주소에서 4바이트만큼 이동하게된다.

    int **parr2;
    parr2 = arr;
    printf("parr[1][1] : %d \n", *(parr2 + 1)); // arr의 주소에서 4바이트만큼 이동하게된다.
    return 0;
}