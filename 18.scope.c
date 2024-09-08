#include <stdio.h>

/*
    1. 변수의 접근 범위
    2. 전역 변수
    3. 변수의 생존 기간
        자신이 정의된 지역을 빠져나갈 때 파괴된다.

    Q.
    전역 변수와 정적 변수의 차이
 */ 



/*
    자신이 정의된 지역을 빠져나갈 때 파괴된다.
    a의 주소값을 반환하지만, a는 스코프를 벗어나는 순간 소멸된다.
*/
int* function1() {
    int a = 3;

    // 소멸된 변수의 주소값을 반환하고 있다.
    return &a;
}


/*
    # static variable (정적 변수)
    지역을 빠져나가도 소멸되지 않는 변수
*/
int* function2() {
    static int a = 2;
    return &a;
}


int main() {
    int a = 1;
    {   
        printf("외부에서 선언된 지역 변수 : %d \n", a); // 1
        int a = 2;
        printf("{}안에 새로 선언된 지역 변수 : %d \n", a); // 2
    }

    printf("외부에서 선언된 지역 변수 : %d \n", a); // 1

    
    /*
        지역 변수는 자신이 정의된 지역을 빠져나갈 때 소멸된다.
    */
    int* pa = function1();
    printf("함수와 함께 소멸된 지역 변수 : %d \n", *pa);

    /*
        정적 변수는 자신이 정의된 지역을 빠져나가도 소멸되지 않는다.
    */
    int* pa2 = function2();
    printf("함수와 함께 소멸되지 않는 정적 변수 : %d \n", *pa2);

    return 0;
}

