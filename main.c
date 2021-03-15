#include <stdio.h>
#include <stdlib.h>
#include "alg.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("insert one natural number");
        exit(0);
    }
    if (atoi(argv[1]) > 2) {
        Number *p = sieve(createPartOf(atoi(argv[1])));
        do {
            printf("%d, ", p->n);
            p = p->next;
        } while (p->next != NULL);
    } else {
        printf("Not valid number (%d is <= 2)", atoi(argv[1]));
        exit(0);
    }

    return 0;
}