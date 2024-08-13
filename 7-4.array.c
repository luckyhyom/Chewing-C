#include <stdio.h>

int main() {
    int a[5];
    int i, average = 0;

    for (i = 0; i < 5; i++)
    {
        printf("%d 번 학생의 점수를 입력하세요. \n", i + 1);
        scanf("%d", &a[i]);
        average += a[i];
    }
    
    average = average / 5;

    printf("평균 점수 : %d", average);

    for (i = 0; i < 5; i++)
    {
        printf("%d 번 학생 점수 : %d \n", i+1, a[i]);
        if(average < a[i]) {
            printf("합격 \n");
        } else if(average > a[i]) {
            printf("불합격 \n");
        }
    }
    
    return 0;
}