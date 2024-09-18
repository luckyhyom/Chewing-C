#include <stdio.h>
#include <string.h>

int main() {
    char str[1024];
    FILE *pa = fopen("a/a.txt", "r");
    FILE *pb = fopen("a/b.txt", "w");

    if(fgets(str, 1024, pa) != NULL) {
        int len = strlen(str);

        for (int i = len -1; i >= 0; i--)
        {
            fputc(str[i], pb);
        }
    }
    fclose(pa);
    fclose(pb);
    return 0;
}