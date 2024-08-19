#include <stdio.h>

int main() {
    int arr[2][3] = {{1,2,3},{4,5,6}};
    //int *parr; // parr은 첫번째 행을 가리킨다. parr[1] = 2

    /**
        arr[a][b] 배열의 arr[x][y] 원소의 주소값 계산 공식 :  arr + 4bx + 4y
        a를 몰라도, parr이 메모리의 시작 주소를 알고 있다. 그 위치에서 한 칸(4bx)씩 이동하면 된다.
     */
    int (*parr)[3]; // 2차원 배열의 포인터는 []연산자로 열의 크기를 알려줘야 메모리 주소를 계산할 수 있다.
    

    parr = arr;
    printf("parr[1][2] : %d , arr[1][2] : %d \n", parr[1][2], arr[1][2]);
    return 0;
}