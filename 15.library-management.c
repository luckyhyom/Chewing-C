#include <stdio.h>

/*
    배운 것
    
    1. 문자열도 크기를 다 정의해줘야 한다. (char book_titles[3][10])
    2. 문자열은 배열이다! 배열은 원소마다 각각 값을 대입해야한다.
        - 문자열도 마찬가지다.
        - 다만, "%s" 는 "\n"가 나올 때 까지 데이터를 읽는 특별한 기능을 한다.
    3. 그래서 문자열 입력할 때 공백은 어떻게 입력하는데?
    4. 한글은 2혹은 3바이트다. 한글자씩 읽으려면? (%c%c)
    5. scanf는 개행문문자열을자(제어문자)를 포함시키지 않는다.
        따라서  비교할 때는 꼭 제어문자를 검사해야한다. -> while (title[i][j]) { j++ }
        그렇지 않으면 같은 "food"를 검색하더라도 끝에서 NUL과 SOH와 비교하게되어 비교 실패함.
    6. 문자열 포인터와 배열의 차이 복습!
*/

/*
    도서 관리 프로그램을 만들어봅시다. 프로그램에는 다음과 같은 기능들이 구현되어 있어야 합니다. (난이도 : 上)

    1. 책을 새로 추가하는 기능 (책의 총 개수는 100 권이라 하자. 이 때, 각 책의 정보는 제목, 저자의 이름, 출판사로 한다)
    2. 책의 제목을 검색하면 그 책의 정보가 나와야 한다.
    3. 위와 마찬가지로 저자, 출판사 검색 기능이 있어야 한다.
    4. 책을 빌리는 기능.
    5. 책을 반납하는 기능
*/

int add_book(char (*title)[21], char (*author)[21], char (*publisher)[21], int *book_number);
int compare(char *original, char *search_string);
int borrow_book(char (*title)[21], char (*author)[21], char (*publisher)[21], int *is_rent, int book_number);
int return_book(char (*title)[21], char (*author)[21],char (*publisher)[21], int *is_rent, int book_number);

int main() {
    char title[100][21] = {0,}; // 최대 20글자의 제목 100개
    char author[100][21] = {0,}; // 0으로 초기화 하지 않으면 더미 데이터 때문에 is_empty 함수 오류 생김
    char publisher[100][21] = {0,};
    int is_rent[100] = {0,};

    int book_number = 0;
    //int index = 0;

    while (1)
    {
        int selected_menu = 1;
        printf("메뉴를 선택해주세요. \n(1) 도서 추가 \n(2) 도서 제목 검색 \n(3) 저자 검색 \n(4) 출판사 검색 \n(5) 도서 대여 \n(6) 도서 반납 \n");
        scanf("%d", &selected_menu);

        if(selected_menu == 1) {
            //char (*p_title)[100][21] = 
            add_book(title, author, publisher, &book_number);
        }
        else if(selected_menu == 2) {
            char search_title[21];
            printf("도서 제목을 입력해주세요. : \n");
            scanf("%s", search_title);
            
            for (int i = 0; i < 100; i++)
            {
                if(compare(title[i], search_title) == 0) {
                    continue;
                }
                printf("\"%s\" 저자의 도서 \"%s\" 이(가) 조회되었습니다. (출판사: %s, 책 번호: %d) \n", author[i], title[i], publisher[i], i);
            }
        }
        else if(selected_menu == 3) {
            char search_author[21];
            printf("저자 이름을 입력해주세요. : \n");
            scanf("%s", search_author);
            for (int i = 0; i < 100; i++)
            {   
                if(compare(author[i], search_author) == 0) {
                    continue;
                }
                printf("\"%s\" 저자의 도서 \"%s\" 이(가) 조회되었습니다. (출판사: %s, 책 번호: %d) \n", author[i], title[i], publisher[i], i);
            }
        }
        else if(selected_menu == 4) {
            char search_publisher[21];
            printf("출판사 이름을 입력해주세요. : \n");
            scanf("%s", search_publisher);
            for (int i = 0; i < 100; i++)
            {   
                if(compare(publisher[i], search_publisher) == 0) {
                    continue;
                }
                printf("\"%s\" 저자의 도서 \"%s\" 이(가) 조회되었습니다. (출판사: %s, 책 번호: %d) \n", author[i], title[i], publisher[i], i);
            }
        }
        else if(selected_menu == 5) {
            int rent_book_number;
            printf("대여할 도서의 번호를 입력해주세요. : \n");
            scanf("%d", &rent_book_number);
            borrow_book(title, author, publisher, is_rent, rent_book_number);
        }
        else if(selected_menu == 6) {
            int rent_book_number;
            printf("반납할 도서의 번호를 입력해주세요. : \n");
            scanf("%d", &rent_book_number);
            return_book(title, author, publisher, is_rent, rent_book_number);
        }
        else {
            break; // 프로그램 종료.
        }
    }
    
}

int add_book(char (*title)[21],char (*author)[21],char (*publisher)[21], int *book_number) {
    printf("도서 제목을 입력해주세요. : \n");
    scanf("%s", title[*book_number]);

    printf("저자 이름을 입력해주세요. : \n");
    scanf("%s", author[*book_number]);

    printf("출판사 이름을 입력해주세요. : \n");
    scanf("%s", publisher[*book_number]);

    printf("\"%s\" 저자의 도서 \"%s\" 이(가) 추가되었습니다. (출판사: %s, 책 번호: %d) \n", author[*book_number], title[*book_number], publisher[*book_number], *book_number);
    printf("현재 총 도서 수: %d", *book_number + 1);
    (*book_number)++;

    return 1;
}

int compare(char *original, char *search_string) {
    if(!(*original)) { // SOH는 공백이면서도 1인데.. 어떻게 false가 되는거지?
        return 0;
    }

    while (*original)
    {
        if(*original != *search_string) {
            return 0;
        }
        original++;
        search_string++;
    }
    
    return 1;
}

int borrow_book(char (*title)[21], char (*author)[21], char (*publisher)[21], int *is_rent, int book_number) {
    if(title[book_number][0] == '\0') {
        printf("등록되지 않은 도서 번호입니다.");
        return 0;
    } 
    
    if(is_rent[book_number] == 1) {
        printf("현재 대여중인 도서입니다.");
        return 0;
    }

    is_rent[book_number] = 1;
    printf("\"%s\" 저자의 도서 \"%s\" 을(를) 대여했습니다. (출판사: %s, 책 번호: %d) \n", author[book_number], title[book_number], publisher[book_number], book_number);
    return 1;
}

int return_book(char (*title)[21], char (*author)[21], char (*publisher)[21], int *is_rent, int book_number) {
    if(title[book_number][0] == '\0') {
        printf("등록되지 않은 도서 번호입니다.");
        return 0;
    } 
    
    if(is_rent[book_number] == 0) {
        printf("현재 대여중인 도서가 아닙니다.");
        return 0;
    }

    is_rent[book_number] = 0;
    printf("\"%s\" 저자의 도서 \"%s\" 을(를) 반납했습니다. (출판사: %s, 책 번호: %d) \n", author[book_number], title[book_number], publisher[book_number], book_number);
    return 1;
}