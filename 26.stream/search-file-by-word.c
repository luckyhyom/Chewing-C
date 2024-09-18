#include <dirent.h> 
#include <stdio.h> 
#include <string.h>

int main(void) {
    char word[255];
    int length;

    printf("파일의 내용에 특정 단어가 포함된 파일을 검색합니다. \n");
    printf("검색할 단어를 입력해주세요 : \n");
    scanf("%s", word);
    length = strlen(word);

    printf("word : %s, length : %d \n", word, length);

    char path[255] = "./a";
    char path_and_file_name[255];

    DIR *d;
    struct dirent *dir;
    d = opendir(path);

    if (d) {
        while ((dir = readdir(d)) != NULL) {
            // '.'과 '..'은 건너뜀
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue;
            }

            // 경로와 파일 이름 결합
            snprintf(path_and_file_name, sizeof(path_and_file_name), "%s/%s", path, dir->d_name);
            printf("파일 경로: %s \n", path_and_file_name);

            // 파일 열기
            FILE *p = fopen(path_and_file_name, "r");
            if (p == NULL) {
                printf("파일을 열 수 없습니다: %s\n", path_and_file_name);
                continue;
            }

            // 파일 내용 검색
            char line[1024]; // 한번에 읽어들일 수 있는 최대 크기
            int found = 0;
            while (fgets(line, sizeof(line), p) != NULL) {
                if (strstr(line, word) != NULL) {
                    printf("찾았구나! 파일: %s, 내용: %s", dir->d_name, line);
                    found = 1;
                    break;
                }
            }

            fclose(p);

            if (!found) {
                printf("단어를 찾을 수 없습니다. 파일: %s\n", dir->d_name);
            }
        }
        closedir(d);
    } else {
        printf("디렉토리를 열 수 없습니다: %s\n", path);
    }

    return 0;
}
