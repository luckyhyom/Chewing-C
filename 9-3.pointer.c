#include <stdio.h>
int main() {
    int a;
    int* pa = &a;
    printf("pa : %p \n", pa);
    printf("pa + 1 : %p \n", pa + 1); // 자료형 만큼 한칸 더! ( (자료형 * i) 만큼 더한다. )

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    int i;
    for (i = 0; i < 10; i++)
    {
        printf("배열의 %d 번째의 메모리 주소 : %p \n", i + 1, &arr[i]); 
    }
    
    /* 배열의 변수는 배열의 첫번째 요소의 주소값을 가지고있다. */
    printf("arr : %p \n", arr); 
    printf("&arr[0] : %p \n", &arr[0]);

    /* 즉, []안의 숫자는.. 메모리 시작 위치에서부터, 자료형 크기 * n 만큼 이동해서 그 위치의 데이터를 보여달라는 뜻 */
    printf("arr[1] : %d \n", arr[1]); // 시작 주소로 부터 한칸 이동해주세요~!
    printf("*(&arr[0] + 1) : %d \n", *(&arr[0] + 1)); // 시작 주소로 부터 한칸 이동해주세요~!
    return 0;
}