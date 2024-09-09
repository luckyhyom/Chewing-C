#include <stdio.h>
#include "str.h"

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