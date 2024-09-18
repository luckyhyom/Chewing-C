#include <stdio.h>
#include <string.h>
#define CHAR_LENGTH 255
#define TEXT_LENGTH 65535

int main() {
    char path[CHAR_LENGTH];
    char file_name[CHAR_LENGTH];
    char path_and_file_name[CHAR_LENGTH + CHAR_LENGTH];
    char contents[TEXT_LENGTH];

    printf("파일 생성 프로그램이 실행되었습니다. \n");
    printf("환영합니다! \n");

    printf("파일을 생성할 경로를 입력해주세요 (folder_name/): ");
    scanf("%s", path);
    getchar();
    printf("\n");

    printf("생성할 파일명을 입력해주세요 (a.txt): ");
    scanf("%s", file_name);
    getchar();
    printf("\n");

    memmove(path_and_file_name, path, strlen(path));
    memmove(path_and_file_name + strlen(path), file_name, strlen(file_name));
    printf("%s \n", path_and_file_name);

    printf("내용을 입력해주세요: ");
    fgets(contents, sizeof(contents), stdin);

    FILE *pf;
    pf = fopen(path_and_file_name, "w");

    if(pf == NULL) {
        printf("Something went wrong!");
        return 0;
    }

    fputs(contents, pf);

    fclose(pf);

    return 0;
}