#include <stdio.h>

int main () {
    int arr[2][3][3] = {{{1,2,4,},{5,6,7},{8,9,10}},{{11,12,13},{14,15,16},{17,18,19}}};
    int (*parr)[3][3];
    parr = arr;
    printf("arr[0][1][1] : %d, parr[0][1][1] : %d \n", arr[0][1][1], parr[0][1][1]);
    return 0;
}