#include "alg.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

Number *crivello(Number *number) {
    Number *prec = number;
    for (Number *p = number; p->next != NULL; p = p->next) {
        for (Number *actual = p->next; actual->next != NULL;
             actual = actual->next) {
            if (actual->n % p->n == 0) {
                prec->next = actual->next;
                prec = prec->next;
            } else
                prec = actual;
        }
    }
    return number;
}

Number* createPartOf(long start, long end) {
    Number *number = (Number *) malloc(sizeof(Number)), *p = number;

    for (long j = start; j <= end; j++) {
        p->n = j;
        p->next = malloc(sizeof(Number));
        p = p->next;
    }
    return number;
}
