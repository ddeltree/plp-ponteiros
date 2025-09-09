// Exemplo 3: Diferença entre char s[] e const char *

#include <stdio.h>
#include "utils/table.h"

int main(void) {
    char s1[] = "hello";      // array mutável
    const char *s2 = "world"; // literal imutável
    
    printTable(3, 2,
        "Operacao", "Novo Valor",
        "char s1[]", fmtStr(s1),
        "const char *s2", fmtStr(s2)
    );
    
    s1[0] = 'H';    // permitido: estamos modificando o array local
    // s2[0] = 'w'; // ERRO: comportamento indefinido
    s2 = "World";   // permitido: s2 aponta para outro literal

    printTable(3, 3,
        "Operacao", "Modificacao", "Novo Valor",
        "char s1[]", "modificado", fmtStr(s1),
        "const char *s2", "substituido", fmtStr(s2)
    );

    return 0;
}

/* Saída esperada:
+----------------+------------+
| Operacao       | Novo Valor |
+----------------+------------+
| char s1[]      | hello      |
+----------------+------------+
| const char *s2 | world      |
+----------------+------------+
+----------------+-------------+------------+
| Operacao       | Modificacao | Novo Valor |
+----------------+-------------+------------+
| char s1[]      | modificado  | Hello      |
+----------------+-------------+------------+
| const char *s2 | substituido | World      |
+----------------+-------------+------------+
*/