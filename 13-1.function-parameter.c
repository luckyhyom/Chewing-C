#include <stdio.h>

int bank(int money);
int sum(int to);

int main() {
    int money = 3000;
    printf("bank(money) : %d \n", bank(money));
    printf("money : %d \n", money);
    printf("sum(10) : %d \n", sum(10));
    return 0;
}

/* 
    매개 변수가 int 자료형일 때
    함수가 호출 될 때 int 자료형 변수가 초기화되어 메모리에 저장된다.
    인자의 값을 복사할 뿐, 호출하는 곳에 있던 인자에는 아무런 영향을 주지 않는다.
*/
int bank(int money) {
    return money += 1000;
}

int sum(int to) {
    int sum = 0;
    int i;
    for (i = 0; i <= to; i++)
    {
        sum+=i;
    }
    return sum;
}
