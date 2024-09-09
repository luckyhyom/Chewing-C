int add_book(char (*title)[21],char (*author)[21],char (*publisher)[21], int *book_number);
int borrow_book(char (*title)[21], char (*author)[21], char (*publisher)[21], int *is_rent, int book_number);
int return_book(char (*title)[21], char (*author)[21], char (*publisher)[21], int *is_rent, int book_number);