#include <stdio.h>

int main() {
    //int arr[2][3] = {{1,2,3},{4,5,6}};
    //int **parr;
    int arr[3] = {1,2,3};
    int (*parr)[3];
    parr = &arr;

    printf("arr[1] : %d \n", arr[1]);
    printf("*(arr + 1)) : %d \n", *(arr + 1)); // arr = &arr[0]
    printf("*(&arr[0] + 1)) : %d \n", *(&arr[0] + 1)); // &arr[0] = &(*(arr + 0))
    printf("*(&(*(arr + 0)) + 1)) : %d \n", *(&(*(arr + 0)) + 1)); // 무한 반복........ -_- 뭐여

    printf("*(&(arr[1]))) : %d \n", *(&(arr[1])));
    printf("*(&(*(arr + 1)))) : %d \n", *(&(*(arr + 1))));
    printf("(*parr)[1]) : %d \n", (*parr)[1]); // *parr = arr = &arr[0]

    /*
        int arr[2][3] = {{1,2,3},{4,5,6}};

        결론:
        arr : &arr[0]
        *arr : arr[0] -> &arr[0][0]
        **arr : arr[0][0]

        (부연 설명)
        1. arr -> 배열의 첫 번째 행인 arr[0]을 가리킨다.
        arr은 int[3] 크기의 1차원 배열을 가리키는 포인터처럼 동작한다.
        *(arr + 0)은 arr[0]이며, 이는 첫 번째 행의 시작 주소를 의미한다.
        따라서 *(arr + 0)[0]은 arr[0][0]을 가리킨다.

        2. arr -> &arr[0] (배열의 첫 번째 행인 arr[0]을 가리킨다).
        -> *(&arr[0])은 첫 번째 요소인 arr[0]을 의미하며, 이는 &arr[0][0]과 동일하다.

    */
    int arr2[2][3] = {{1,2,3},{4,5,6}};
    printf("-> %d \n", *(arr2 + 1 * 3 + 2)); // ❌
    printf("-> %d \n", *(*(arr2 + 1) + 2)); // ✅

    printf("-> %d \n", *(arr2 + 1)[2]); // ❌
    printf("-> %d \n", (*(arr2 + 1))[2]); // ✅

    printf("-> %d \n", arr2[1][2]); // ✅
    return 0;
}