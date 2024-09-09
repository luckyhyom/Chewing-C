#include <stdio.h>
#include "human.c"

int main() {
    struct Human me = Create_Human("Hyomin", 23, MALE);
    Print_Human(&me);
    return 0;
}