#include <stdio.h>
#include <stdlib.h>

int main() {
    int students_count = 0;
    int *scores;
    int sum = 0;

    printf("학생의 수 : \n");
    scanf("%d", &students_count);

    scores = (int *)malloc(students_count *  sizeof(int));

    for (int i = 0; i < students_count; i++)
    {
        printf("%d번째 학생의 점수 : \n", i + 1);
        scanf("%d", &scores[i]);
        sum += scores[i];
    }

    for (int i = 0; i < students_count; i++)
    {
        printf("%d번째 학생의 점수 : %d \n", i + 1, scores[i]);
    }
    

    printf("학생의 수 : %d \n", students_count);
    printf("총 점수 : %d \n", sum);
    printf("평균 점수 : %d \n", sum / students_count);

    free(scores);
    return 0;
}