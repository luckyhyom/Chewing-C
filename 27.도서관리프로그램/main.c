#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Book
{
    char name[30];
    char publisher[30];
    char author[30];
    int is_borrowed;
};

void add_book(struct Book *book_list, int *book_count);
void print_book_list(struct Book *book_list, int book_count);
void print_book_list_to_file(struct Book *book_list, int book_count);
void read_book_list_from_file(struct Book *book_list, int *book_count);

int main() {
    struct Book* book_list;
    int book_count = 0;
    int max_book_count;

    printf("최대 도서 갯수를 입력하세요 : \n");
    scanf("%d", &max_book_count);

    book_list = (struct Book*)malloc(sizeof(struct Book) * max_book_count);

    while (1) {
        int menu = 0;
        printf("도서 관리 프로그램 \n");
        printf("메뉴를 선택하세요 \n");
        printf("1. 책을 새로 추가하기 \n");
        printf("2. 책을 검색하기 \n");
        printf("3. 책을 빌리기 \n");
        printf("4. 책을 반납하기 \n");
        printf("5. 프로그램 종료 \n");
        printf("6. 책들의 내용을 book_list.txt 에 출력 \n");
        printf("7. 책들의 내용을 book_list.txt 에서 불러옴 \n");
        printf("8. 책들의 목록을 출력 \n");

        scanf("%d", &menu);

        if(menu == 1) {
            add_book(book_list, &book_count);
        } else if(menu == 6) {
            print_book_list_to_file(book_list, book_count);
        } else if(menu == 7) {
            read_book_list_from_file(book_list, &book_count);
        } else if(menu == 8) {
            print_book_list(book_list, book_count);
        }
    } 
    return 0;
}

void add_book(struct Book *book_list, int *book_count) {
    printf("책 이름: ");
    scanf("%s", book_list[*book_count].name);
    printf("작가 이름: ");
    scanf("%s", book_list[*book_count].author);
    printf("출판사 이름: ");
    scanf("%s", book_list[*book_count].publisher);

    book_list[*book_count].is_borrowed = 0;
    *book_count += 1;
}

void print_book_list(struct Book *book_list, int book_count) {
    printf("책이름/작가/출판사/대여상태 \n");
    for (int i = 0; i < book_count; i++)
    {
        printf("%s / %s / %s / %d \n", book_list[i].name, book_list[i].author, book_list[i].publisher, book_list[i].is_borrowed);
    }
}

void print_book_list_to_file(struct Book *book_list, int book_count) {
    FILE *p = fopen("book-list.txt", "w");
    printf("책이름/작가/출판사/대여상태 \n");
    fprintf(p, "%d\n", book_count);
    for (int i = 0; i < book_count; i++)
    {
        fprintf(p, "%s\n%s\n%s\n%d\n", book_list[i].name, book_list[i].author, book_list[i].publisher, book_list[i].is_borrowed);
    }
    fclose(p);
}

void read_book_list_from_file(struct Book *book_list, int *book_count) {
    FILE *p = fopen("book-list.txt", "r");
    char line[1024];
    fgets(line, 1024, p);
    
    int count = 0;
    for (int i = 0; i < strlen(line); i++)
    {
        if(line[i] == '\n') continue;
        count = count * 10 + (line[i] - '0');
    }
    printf("%d \n", count);
    *book_count = count;
    
    for (int i = 0; i < count; i++)
    {
        fgets(book_list[i].name, sizeof(book_list[i].name), p);
        book_list[i].name[strcspn(book_list[i].name, "\n")] = '\0';  // 개행 문자 제거

        fgets(book_list[i].author, sizeof(book_list[i].author), p);
        book_list[i].author[strcspn(book_list[i].author, "\n")] = '\0';  // 개행 문자 제거

        fgets(book_list[i].publisher, sizeof(book_list[i].publisher), p);
        book_list[i].publisher[strcspn(book_list[i].publisher, "\n")] = '\0';  // 개행 문자 제거

        char temp[1024];
        fgets(temp, sizeof(temp), p);
        book_list[i].is_borrowed = atoi(temp);
    }

    fclose(p);
}
