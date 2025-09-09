// Exemplo 1: Uso de & (address-of) e * (dereference)
#include <stdio.h>
#include <stdbool.h>
#include "utils/table.h"

int main(void) {
    int x = 42;     // variável inteira normal
    int *p = &x;    // ponteiro p recebe o endereço de x

    printTable(4, 2, 
        "Valor", fmtInt(x),         // valor decimal
        "Endereco", fmtPtr(&x),     // endereço hexadecimal
        "Ponteiro", fmtPtr(p),      // endereço hexadecimal (igual ao de x)
        "Desreferencia", fmtInt(*p) // valor decimal (conteúdo do endereço apontado)
    );
    
    printf("\n");

    *p = 100;
    printTable(2, 2, 
        "Valor alterado via ponteiro", fmtInt(x),
        "Endereco inalterado", fmtPtr(&x)     // endereço continua o mesmo
    );

    return 0;
}

/* Saída esperada (exceto endereços):
+---------------+----------------+
| Valor         | 42             |
+---------------+----------------+
| Endereco      | 0x7fffffffd114 |
+---------------+----------------+
| Ponteiro      | 0x7fffffffd114 |
+---------------+----------------+
| Desreferencia | 42             |
+---------------+----------------+

+-----------------------------+----------------+
| Valor alterado via ponteiro | 100            |
+-----------------------------+----------------+
| Endereco inalterado         | 0x7fffffffd114 |
+-----------------------------+----------------+
*/