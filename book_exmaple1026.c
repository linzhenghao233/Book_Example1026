#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
typedef int DataType;
typedef struct {
    int i, j;
    DataType v;
} TriTupleNode;

// Three-tuple table
typedef struct {
    TriTupleNode data[MAXSIZE];
    int m, n;
    int t;
} TriTupleTable;

void TransMatrix(TriTupleTable* b, TriTupleTable* a) {
    int pa, pb, col;

    b->m = a->n;
    b->n = a->m;
    b->t = a->t;
    if (b->t <= 0) {
        printf("A = 0\n");
        exit(0);
    }
    pb = 0;

    for (col = 0; col < a->n; col++) {
        for (pa = 0; pa < a->t; pa++) {
            if (a->data[pa].j == col) {
                b->data[pb].i = a->data[pa].j;
                b->data[pb].j = a->data[pa].i;
                b->data[pb].v = a->data[pa].v;
                pb++;
            }
        }
    }
}

int main(void) {
    TriTupleTable a, b;
    TriTupleNode node[MAXSIZE];
    int num;

    node[0].i = 0; node[0].j = 1; node[0].v = 5;
    node[1].i = 0; node[1].j = 4; node[1].v = 8;
    node[2].i = 1; node[2].j = 0; node[2].v = 1;
    node[3].i = 1; node[3].j = 2; node[3].v = 3;
    node[4].i = 2; node[4].j = 1; node[4].v = -2;
    node[5].i = 3; node[5].j = 0; node[5].v = 6;

    for (num = 0; num < 6; num++) {
        a.data[num].i = node[num].i;
        a.data[num].j = node[num].j;
        a.data[num].v = node[num].v;
    }
    a.m = 4;
    a.n = 5;
    a.t = 6;
    TransMatrix(&b, &a);

    for (num = 0; num < b.t; num++)
        printf("%d, %d, %d\n", b.data[num].i, b.data[num].j, b.data[num].v);

    return 0;
}
