#include <stdio.h>

int copy_str(char *ori, char *copy);

struct Book {
    char title[20];
    char author[20];
    char publisher[20];
    int is_borrowed;
};

int main() {
    struct Book harry_potter;

    copy_str(harry_potter.title, "Harry Potter");
    copy_str(harry_potter.author, "J. K. Rowling");
    copy_str(harry_potter.publisher, "Marvel");
    harry_potter.is_borrowed = 0;

    printf("제목 : %s \n", harry_potter.title);
    printf("작가 : %s \n", harry_potter.author);
    printf("출판사 : %s \n", harry_potter.publisher);
    printf("대여 상태 : %d \n", harry_potter.is_borrowed);
}

int copy_str(char *ori, char *copy) {
    while (*copy)
    {
        printf("%c \n", *copy);
        *ori = *copy;
        ori++;
        copy++;
    }
    *ori = '\0';
    return 1;
}