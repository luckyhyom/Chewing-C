#include <stdio.h>

int bank(int *money);
int swap(int *a, int *b);
int add_number(int *arr);
int print_arr(int *arr);
int max_number(int (*arr)[3]);
int print_arr_desc(int (*arr)[3]);
int* remove_max(int (*arr)[3]);

int main() {
    printf("이자 받기 \n");
    int money = 10000;
    printf("입금 전 money: %d \n", money);
    bank(&money);
    printf("입금 후 money: %d \n", money);
    printf("-----------\n");

    int my_money = 1000;
    int your_money = 500;
    printf("[교환 전] my_money : %d, your money : %d \n", my_money, your_money);
    swap(&my_money, &your_money);
    printf("[교환 후] my_money : %d, your money : %d \n", my_money, your_money);

    printf("-----배열을 인자로------\n");

    int arr[3] = {1,2,3};
    print_arr(arr);
    add_number(arr);
    print_arr(arr);

    print_arr_desc(arr);
    print_arr(arr);

    return 0;
}


int bank(int *money) {
    double interest_rate = 0.05;
    double interest =  (*money) * interest_rate;
    (*money) += interest;
    return 0;
}

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    return 0;
};

/*
    1차원 배열이 매개변수일 때의 문제
        1. 배열의 원소인지 사실 여부를 알 수 없다, 배열이 아닐 수도 있다!
        2. 배열의 길이를 알아야한다. (길이가 고정된다.)
        3. 값을 참조하는 방법은 두가지 밖에 없다.
            3-1. 시작 주소 값으로 참조하기
            3-2. 데이터를 모두 읽어서 복사하기            

            애초에 배열이던 뭐던.. 주소값을 쓰지 않는다면 [데이터를 처음부터 끝까지 다 읽어서 복사]해야한다.
                예를 들어, 함수의 매개변수를 "int arr[3]"로 정의한다면.. 결국 인자를 하드코딩 해야만 한다. => a({1, ...10});
                혹은, 함수 안에서 반복문을 통해 복사본을 만들어야한다.
            
            값을 복사하려면 무조건 원본을 읽어야한다.
*/
int add_number(int *arr) {
    int i;
    for (i = 0; i < 3; i++)
    {
        arr[i]++;
    }
    return 0;
}

int print_arr(int *arr) { // 포인터(주소)를 받지 않으면 배열의 다음 원소를 알 수 없다.
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("%d,", arr[i]);
    }
    printf("\n");
    printf("----------------\n");
}

int max_number(int (*arr)[3]) {
    int i;
    int max = (*arr)[0];
    
    // 배열의 원소 개수 = 배열의 총 크기 / 원소의 크기
    for (i = 0; i < sizeof(*arr) / sizeof((*arr)[0]); i++)
    {
        if((*arr)[i] > max) {
            max = (*arr)[i];
        }
    }
    return max;
}

int print_arr_desc(int (*arr)[3]) { // [problem] 배열의 값을 다 복사하기가 어렵네.. 매개변수를 int arr[3] 처럼 정의하면 좋으련만
    int temp_arr[3];
    int i;
    for (i = 0; i < 3; i++)
    {
        temp_arr[i] = (*arr)[i];
    }
    
    int *selected_arr = temp_arr;

    int j;
    for (j = 3; j > 0; j--)
    {
        printf("selected_arr : %d \n", max_number(selected_arr));
        selected_arr = remove_max(selected_arr);
    }
    return 0;
}

/*
    함수에서 새로운 배열을 만들어 반환할 수 없는가?
    함수가 종료되는 순간 함수에 초기화된 배열도 사라지는가? -> 안사라지고 그대로 메모리에 있는 것 같다.

    <배열의 원소를 내림차순으로 화면에 출력하기>
    방안 1) max가 제거되어 새로 초기화한 배열을 반환한다.
    방안 2) max를 0으로 수정한다.
*/
int* remove_max(int (*arr)[3]) {
    int i;
    for (i = 0; i < 3; i++)
    {
        if((*arr)[i] == max_number(arr)) {
            (*arr)[i] = 0;
        }
    }
    return arr;
}