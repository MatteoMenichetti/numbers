//
// Created by Matteo Menichetti on 25/02/21.
//
#include "alg.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void writeP(Number *p, int fd) {
    printf("%d ", p->n);
    dprintf(fd, "%d\n", p->n);
}

/*Number *create(long i) {
    if (i <= 2)exit(0);
    Number *number = (Number *) malloc(sizeof(Number)), *p = number;

    for (long j = 2; j < i; j++) {
        p->n = j;
        p->next = malloc(sizeof(Number));
        p = p->next;
    }
    return number;
}*/

void crivello(Number *number) {
    int fd = open("primesMiddleExec.txt", O_WRONLY | O_TRUNC | O_CREAT, 0666);
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
        writeP(p, fd);
    }
}

Number *createPartOf(long start, long end) {
    Number *number = (Number *) malloc(sizeof(Number)), *p = number;

    for (long j = start; j <= end; j++) {
        p->n = j;
        p->next = malloc(sizeof(Number));
        p = p->next;
    }
    return number;
}
