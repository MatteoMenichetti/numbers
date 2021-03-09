#include

"alg.h"

#include

<stdio.h>

#include

<stdlib.h>

Number *sieve(Number *number) {
    Number *previous = number;
    for (Number *p = number; p->next != NULL; p = p->next) {
        for (Number *actual = p->next; actual->next != NULL;
             actual = actual->next) {
            if (actual->n % p->n == 0) {
                previous->next = actual->next;
                free(actual);
                previous = previous->next;
            } else
                previous = actual;
        }
    }
    return number;
}

Number *createPartOf(long end) {
    Number *number = (Number *) malloc(sizeof(Number)), *p = number;

    for (long j = 2; j <= end; j++) {
        p->n = j;
        p->next = malloc(sizeof(Number));
        p = p->next;
    }
    return number;
}
