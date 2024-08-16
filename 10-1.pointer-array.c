#include <stdio.h>

/*
    배열은 첫번째 요소의 주소값을 가지고 있는 포인터라고 생각해도 좋다.
    arr[1]; // 배열의 메모리 시작 주소에서 한칸 이동해줘 -> *(&arr[0] + 1)
*/
int main() {
    int arr[3] = {1, 2, 3};
    /* arr은 포인터다! */
    int* parr = arr; // arr = &arr[0] | arr[1] = &arr[0] + 1

    /*
        배열[n] = *(배열의 시작 주소 + n칸)
        n칸 = 자료형 * n

        검증
        printf("arr = %p \n", arr);
        printf("arr = %p \n", arr + 1);
     */
    printf("arr[1] = %d \n", arr[1]); // 주소에서 한칸 이동해라!
    printf("*(arr + 1) = %d \n", *(arr + 1)); // 주소에서 한칸 이동해라!
    printf("(&arr[0])[1] = %d \n", (&arr[0])[1]); // 주소에서 한칸 이동해라!
    printf("parr[1] = %d \n", parr[1]); // 주소에서 한칸 이동해라!
    return 0;
}