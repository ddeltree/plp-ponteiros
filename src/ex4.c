// Função swap com ponteiros

#include <stdio.h>
#include "utils/table.h"

// Função que troca os valores de duas variáveis inteiras usando seus endereços
void swap(int *a, int *b) {
    int tmp = *a;   // guarda valor original de `a`
    *a = *b;        // coloca valor de `b` no endereço de `a`
    *b = tmp;       // coloca valor original de `a` no endereço de `b`
}

int main(void) {
    int x = 10, y = 20;

    printTable(2, 2,
        "Antes x", fmtInt(x),
        "Antes y", fmtInt(y)
    );

    swap(&x, &y);   // passamos os endereços de `x` e `y` para a função

    printTable(2, 2,
        "Depois x", fmtInt(x),
        "Depois y", fmtInt(y)
    );

    return 0;
}

/* Saída esperada (exceto endereços):
+---------+----+
| Antes x | 10 |
+---------+----+
| Antes y | 20 |
+---------+----+
+----------+----+
| Depois x | 20 |
+----------+----+
| Depois y | 10 |
+----------+----+
*/