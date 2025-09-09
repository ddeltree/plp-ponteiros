// Relação entre arrays e ponteiros

#include <stdio.h>
#include "utils/table.h"

void printArray(int *a, int n) {
    // imprime os elementos do array como se fosse um ponteiro
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(void) {
    int a[5] = {10, 20, 30, 40, 50};
    int *p = a; 

    printArray(a, sizeof(a)/sizeof(int)); // decai para ponteiro de `int`

    // Percorre o array mostrando que *(a+i) é equivalente a a[i]
    printTable(6, 3,
        "Indice", "a[i]", "*(p+i)",
        fmtInt(0), fmtInt(a[0]), fmtInt(*(p+0)),
        fmtInt(1), fmtInt(a[1]), fmtInt(*(p+1)),
        fmtInt(2), fmtInt(a[2]), fmtInt(*(p+2)),
        fmtInt(3), fmtInt(a[3]), fmtInt(*(p+3)),
        fmtInt(4), fmtInt(a[4]), fmtInt(*(p+4))
    );

    printTable(4, 2,
        // `a` decai para `&a[0]`
        "Endereco a", fmtPtr(a),
        "Endereco &a[0]", fmtPtr(&a[0]),
        // `p+1` avança `sizeof(int)` bytes para ponteiros de `int`
        "Endereco p", fmtPtr(p),
        "Endereco p+1", fmtPtr(p+1)
    );

    return 0;
}

/* Saída esperada (exceto endereços):
Array: 10 20 30 40 50 
+--------+------+--------+
| Indice | a[i] | *(p+i) |
+--------+------+--------+
| 0      | 10   | 10     |
+--------+------+--------+
| 1      | 20   | 20     |
+--------+------+--------+
| 2      | 30   | 30     |
+--------+------+--------+
| 3      | 40   | 40     |
+--------+------+--------+
| 4      | 50   | 50     |
+--------+------+--------+
+----------------+----------------+
| Endereco a     | 0x7fffffffd0f0 |
+----------------+----------------+
| Endereco &a[0] | 0x7fffffffd0f0 |
+----------------+----------------+
| Endereco p     | 0x7fffffffd0f0 |
+----------------+----------------+
| Endereco p+1   | 0x7fffffffd0f4 |
+----------------+----------------+
*/