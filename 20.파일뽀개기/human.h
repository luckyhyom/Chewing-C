// 타입 혹은 인터페이스가 정의된 파일.
enum { MALE, FEMALE };
struct Human {
    char name[20];
    int age;
    int gender;
};

struct Human Create_Human(char *name, int age, int gender);
int Print_Human(struct Human *human);
