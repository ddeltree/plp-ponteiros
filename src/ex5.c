// Alocacao dinamica de array via T**

#include <stdio.h>
#include <stdlib.h>
#include "utils/table.h"

// Função que cria dinamicamente um array de n inteiros
// e retorna o ponteiro ao chamador via parâmetro T**
int make_array(int **out, size_t n) {
    *out = malloc(n * sizeof **out);
    // malloc retorna NULL se a heap estiver cheia
}

int main(void) {
    int *arr = NULL;
    size_t n = 5;

    make_array(&arr, n);
    if (arr == NULL) {
        fprintf(stderr, "Erro de alocacao\n");
        return 1;
    }

    printTable(2, 2,
        "Array", fmtPtr(arr),
        "Endereco", fmtPtr(&arr)
    );

    // Popula o array com quadrados do índice
    for (size_t i = 0; i < n; i++) arr[i] = (int)(i*i);
    
    printTable(4, 3,
        "Indice", "Valor arr[i]", "Endereco &arr[0]",
        "0", fmtInt(arr[0]), fmtPtr(&arr[0]),
        "1", fmtInt(arr[1]), fmtPtr(&arr[1]),
        "2", fmtInt(arr[2]), fmtPtr(&arr[2])
    );

    free(arr);  // libera memória alocada anteriormente
    arr = NULL; // boa prática

    return 0;
}

/* Saída esperada (exceto endereços):
+----------+----------------+
| Array    | 0x5555555592a0 |
+----------+----------------+
| Endereco | 0x7fffffffd0f8 |
+----------+----------------+
+--------+--------------+------------------+
| Indice | Valor arr[i] | Endereco &arr[0] |
+--------+--------------+------------------+
| 0      | 0            | 0x5555555592a0   |
+--------+--------------+------------------+
| 1      | 1            | 0x5555555592a4   |
+--------+--------------+------------------+
| 2      | 4            | 0x5555555592a8   |
+--------+--------------+------------------+
*/
