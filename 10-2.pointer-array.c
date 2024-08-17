#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int *parr = arr; // arr은 포인터다
    int sum = 0;

    while (parr - arr < 5)
    {
        /* code */
        sum += *parr;
        parr++;
    }

    printf("%d\n", sum);
    

    return 0;
}