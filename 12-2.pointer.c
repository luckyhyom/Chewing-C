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

    return 0;
}