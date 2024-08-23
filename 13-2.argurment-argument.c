#include <stdio.h>

int bank(int *money);
int swap(int *a, int *b);
int add_number(int *arr);
int print_arr(int *arr);

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