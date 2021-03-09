#include <stdio.h>
#include "alg.h"

int main(int argc, char *argv[]) {
    int n = 100;
    Number *p = crivello(createPartOf(2, n));
    do {
        printf("%d", p->n);
        p = p->next;
    } while (p->next != NULL);

    return 0;
}