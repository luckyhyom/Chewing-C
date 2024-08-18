#include <stdio.h>

int main() {
    int arr[2][3] = {{1,2,3},{4,5,6}};
    printf("size of arr : %d \n", sizeof arr); // 2(행) * 3(열) * 자료형 크기(4) = 24byte
    printf("size of arr[0] : %d \n", sizeof arr[0]); // 요소 개수(3) * 자료형 크기(4) = 12
    printf("size of arr[0][0] : %d \n", sizeof arr[0][0]); // 요소의 자료형 크기 = 4
    
    printf("전체 크기 : %d \n", sizeof(arr));
    printf("전체 열의 개수 : %d \n", sizeof(arr[0]) / sizeof(arr[0][0])); // 3 / 1
    printf("전체 행의 개수 : %d \n", sizeof arr / sizeof arr[0]); // 6 / 3

    /*
        배열의 첫번째 요소의 포인터
        arr[0][0] = *(&arr + (0 * 12) + (0 * 4))
        arr[0][1] = *(&arr + (0 * 12) + (1 * 4))

        arr의 요소는 int 자료형 3개의 배열이다.
        arr이든 arr[0]이든, arr[0][0]이든 그냥 배열의 첫번째 요소다.
     */
    printf("arr : %p \n", arr);
    printf("arr[0] : %p \n", arr[0]);
    printf("&arr[0][0] : %p \n", &arr[0][0]);

    /*
        배열의 두번째 요소의 포인터
        arr[1][0] = *(&arr + (1 * 12) + (0 * 4))
        arr[1][1] = *(&arr + (1 * 12) + (1 * 4))
     */
    printf("&arr[1] : %p \n", arr[1]);
    printf("&arr[1][0] : %p \n", &arr[1][0]);


    printf("&arr : %p \n", &arr);
    printf("&arr[0] + 1 : %p \n", &arr[0] + 1); // 한 행의 크기(열의 크기) 만큼 더하기
    printf("&arr[0][0] + 1 : %p \n", &arr[0][0] + 1); // 한 행의 한 열만큼 더하기
    return 0;
}