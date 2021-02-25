//
// Created by Matteo Menichetti on 25/02/21.
//

#ifndef NUMBERS_ALG_H
#define NUMBERS_ALG_H

#endif //NUMBERS_ALG_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct array {
    int n;
    struct array *next;
} Number;
void writeP(Number * p, int fd);
Number* create(long i);
void crivello(Number *number);
Number* createPartOf(long start, long end);