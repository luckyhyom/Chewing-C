#include <stdio.h>

int bank(int *money);
int swap(int *a, int *b);

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