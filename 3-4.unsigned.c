#include <stdio.h>

int main()
{
    unsigned int a = -1;
    /*
        1. int 이므로 일단 -1을 2진수로 해석한다. -1(10진수) = 0xFFFFFFFF = 1111 1111 1111 1111
        2. unsigned 이므로.. 해석된 2진수를 양수로 친다. 0xFFFFFFFF = 최댓값
            (해석된 2진수를 2의 보수 표현 체계로 해석하지 않음)
    */
    printf("a: %u \n", a); // 4294967295 (%u : unsigned type으로 해석해줘)

    return 0;
}