#include <stdio.h>

enum Color { RED, BLUE, WHITE, BLACK };

/*
    상수인 문자열의 배열을 선언하고 싶다면 문자열 리터럴 포인터를 사용한다.
    이 때 const를 사용하지 않으면 포인터가 가리키는 대상을 수정할 수 있게 되므로 const 키워드를 사용해야한다.
*/
void print_color(enum Color color_name) {
    const char *color[4] = { "Red", "Blue", "White", "Black" };
    // color[3] = "ERROR";
    printf("%s \n", color[color_name]);
}


/**
 * 사람이 이해할 수 있는 코드를 사용하면서 메모리에는 실제 문자열이 아닌 int 자료형으로 저장된다.
 * MALE = 0, FEMALE = 1
 * 
 * if(human.gender == 0) {} // 사람이 이해하기 어려움
 * if(human.gender == "MALE") {} // 메모리를 비효율적으로 사용함
 * if(human.gender == MALE) {} // 읽기도 편하고, 메모리도 아끼고
 */
int main() {
    enum Color picked_color;
    picked_color = BLUE;
    printf("%d \n", picked_color);

    print_color(BLACK);

    return 0;
}


