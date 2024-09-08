#include <stdio.h>

int copy_str(char *ori, char *copy);

struct Person {
    char name[20];
    int age;
};

int main() {
    struct Person a, b;

    copy_str(a.name, "Hanni Pham");
    a.age = 20;

    b = a; // 배열과 다르게 구조체는 대입이 가능한 이유는? 배열은 원소 하나씩 순회하며 값을 대입해야하는데.. 메모리 주소 끝에 플래그 유무의 차이가 있는건가.

    printf("%s \n", b.name);

    struct Person c = {
        "Yerin",
        28,
    };

    printf("%s \n", c.name);
}

int copy_str(char *ori, char *copy) {
    while (*copy)
    {
        *ori = *copy;
        ori++;
        copy++;
    }
    *ori = '\0';
    return 1;
}