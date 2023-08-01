
#include <stdlib.h>
#include <stdio.h>

struct person {
    char* name;
    int age;
};

typedef struct  person person_t;


int main(){
    char* x;
    person_t* p1 = calloc(sizeof(person_t),1);
    printf("%s",p1->name);
    if (p1->name == NULL) {
        printf("true");
    }
}