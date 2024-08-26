#include <stdio.h>

int compare_string(char *str, char *str2);

int main() {
    char str[] = "This is string data. \n";
    char str2[] = "This is string data. \n";

    if(compare_string(str, str2)) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}

int compare_string(char *str, char *str2) {
    int i;
    while (str[i])
    {
        if (str[i] != str2[i]) return 0;
        i++;
    }
    return 1;
}