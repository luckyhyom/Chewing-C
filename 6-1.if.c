#include <stdio.h>

int main() {
    float average_score;
    float language, math, science, history, economy;

    printf("언어 점수를 입력하세요 : \n");
    scanf("%f", &language);
    printf("수학 점수를 입력하세요 : \n");
    scanf("%f", &math);
    printf("과학 점수를 입력하세요 : \n");
    scanf("%f", &science);
    printf("역사 점수를 입력하세요 : \n");
    scanf("%f", &history);
    printf("경제 점수를 입력하세요 : \n");
    scanf("%f", &economy);

    average_score = (language + math + science + history + economy) / 5;

    if(average_score >= 90) {
        printf("평균 90점 이상이네요!");
    } else if (average_score >= 50) {
        printf("평균 50점 이상이네요!");
    } else if (average_score >= 10) {
        printf("평균 10점 이상이네요!");
    } else {
        printf("좀 그렇네요!");
    }

    return 0;
}