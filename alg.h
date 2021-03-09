
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct array {
    int n;
    struct array *next;
} Number;

Number *crivello(Number *number);

Number *createPartOf(long start, long end);