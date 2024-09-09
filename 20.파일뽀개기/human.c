#include <stdio.h>
#include "human.h"
#include "str.c"


struct Human Create_Human(char *name, int age, int gender) {
    struct Human human = {
        name,
        age,
        gender,
    };
    return human;
}

int Print_Human(struct Human *human) {
    printf("name : %s \n", human->name);
    printf("age : %d \n", human->age);
    if(human->gender == MALE) {
        printf("gender : male \n");
    } else if (human->gender == FEMALE) {
        printf("gender : female \n");
    }
    return 0;
}
