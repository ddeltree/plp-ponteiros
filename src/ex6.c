// Ponteiro para funcao com qsort

#include <stdio.h>
#include <stdlib.h>
#include "utils/table.h"

// Implementação simples do bubble sort usando a função comparadora
void bubble_sort(int arr[], int n, int (*cmp)(const void*, const void*)) {
    // `int (*cmp)(const void*, const void*)` é um ponteiro para função
    // que recebe dois ponteiros para void e retorna um int
    
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (cmp(&arr[j], &arr[j+1]) > 0) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

// Função comparadora usada pelo qsort
int cmp_ints(const void *a, const void *b) {
    int ia = *(const int*)a; // casting e desreferenciação do ponteiro
    int ib = *(const int*)b;
    return ia - ib; // <0 se ia < ib, 0 se ia == ib, >0 se ia > ib
}

int main(void) {
    int v[] = {42, 5, 17, 3, 99, 42};
    int n = sizeof v / sizeof v[0]; // 6

    printTable(1, 7,
        "Antes ",
        fmtInt(v[0]), fmtInt(v[1]), fmtInt(v[2]),
        fmtInt(v[3]), fmtInt(v[4]), fmtInt(v[5])
    );

    // qsort recebe o vetor, o tamanho, o tamanho de cada elemento e a função comparadora
    qsort(v, n, sizeof v[0], cmp_ints);
    bubble_sort(v, n, cmp_ints); // Usando bubble_sort com a mesma função comparadora

    printTable(1, 7,
        "Depois",
        fmtInt(v[0]), fmtInt(v[1]), fmtInt(v[2]),
        fmtInt(v[3]), fmtInt(v[4]), fmtInt(v[5])
    );

    return 0;
}

/* Saída esperada:
+--------+----+---+----+---+----+----+
| Antes  | 42 | 5 | 17 | 3 | 99 | 42 |
+--------+----+---+----+---+----+----+
+--------+---+---+----+----+----+----+
| Depois | 3 | 5 | 17 | 42 | 42 | 99 |
+--------+---+---+----+----+----+----+
*/