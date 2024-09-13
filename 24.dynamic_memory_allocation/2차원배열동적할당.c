#include <stdio.h>
#include <stdlib.h>


void 포인터배열을사용하기();
void 이차원배열포인터로참조하기();
void print_array(int x, int (*arr)[x], int y);

int main() {
    //포인터배열을사용하기();
    이차원배열포인터로참조하기();
    return 0;
}

/*
    2차원 배열을 흉내내지만, 메모리에 연속된 구조로 할당되지 않는다.
    
    실제 2차원 배열과의 차이점
    1. 값을 조회하기 위해 연산이 한번 추가되는정도의 오버헤드가 있을 것 같다?
    2. 메모리를 할당하고 해제하는 과정이 여러번이다.
*/
void 포인터배열을사용하기() {
    int x,y;
    printf("arr[x][y] 2차원 배열을 만든다. x와 y를 입력 : \n");
    scanf("%d", &x);
    scanf("%d", &y);
    int **arr;
    arr = (int**)malloc(sizeof(int*) * x); // 포인터 갯수만큼의 메모리가 할당된다.
    for (int i = 0; i < x; i++)
    {
        arr[i] = (int*)malloc(sizeof(int) * y); // 실질적인 배열의 크기가 이때 할당된다. 하나씩..
    }
    
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            arr[i][j] = i * y + j;
        }
    }

    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    // print_array(x, *arr, y); 안되는 이유는?

    for (int i = 0; i < x; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

/*
    배열의 데이터가 메모리에 연속적으로 할당되어 있기에 메모리 해제를 한번만 하면 된다.
*/
void 이차원배열포인터로참조하기() {
    int x;
    int y;

    printf("arr[x][y] 2차원 배열을 만든다. x를 입력 : \n");
    scanf("%d", &x);

    printf("arr[x][y] 2차원 배열을 만든다. y를 입력 : \n");
    scanf("%d", &y);

    int (*arr)[y] = (int(*)[y])malloc(x * y * sizeof(int));

    // 배열 초기화 (예: arr2 배열을 1~size*size2 값으로 초기화)
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            arr[i][j] = i * y + j; // 배열 값 할당
        }
    }

    print_array(x, arr, y);

    free(arr);
}

void print_array(int x, int (*arr)[x], int y) {
    // 배열 출력
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}


/*
    (고민했던 흔적)
    1차원 배열의 경우 단순히 자료형의 개수만 입력하면 됐었다.
    2차원 배열은? 포인터가 두개여야할까?
    전체 사이즈 + 단위..
    
    int (*arr2)[size] = (int(*)[size])malloc(size * sizeof(*arr));

    1. 전체 길이 정하기 (size1 * size2 * typeof(int))
    2. 단위 크기 정하기 int (*)[]
*/