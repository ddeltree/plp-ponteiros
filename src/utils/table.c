#include <stdio.h>
#include <string.h>
#include "table.h"
#include <stdarg.h>
#include <stdlib.h>

void printTableStrings(int rows, int cols, const char *m[]) {
    int colWidths[cols];

    // calcula largura máxima de cada coluna
    for (int c = 0; c < cols; c++) {
        colWidths[c] = 0;
        for (int r = 0; r < rows; r++) {
            const char *val = m[r*cols + c]; // acesso linear
            int len = strlen(val);
            if (len > colWidths[c]) colWidths[c] = len;
        }
    }

    // imprime tabela
    for (int r = 0; r < rows; r++) {
        // linha horizontal
        for (int c = 0; c < cols; c++) {
            printf("+");
            for (int i = 0; i < colWidths[c] + 2; i++) printf("-");
        }
        printf("+\n");

        // conteúdo da linha
        for (int c = 0; c < cols; c++) {
            const char *val = m[r*cols + c];
            printf("| %-*s ", colWidths[c], val);
        }
        printf("|\n");
    }

    // última linha horizontal
    for (int c = 0; c < cols; c++) {
        printf("+");
        for (int i = 0; i < colWidths[c] + 2; i++) printf("-");
    }
    printf("+\n");
}

void printTable(int rows, int cols, ...) {
    va_list args;
    va_start(args, cols);

    int n = rows * cols;
    const char *mat[n];

    for (int i = 0; i < n; i++) {
        mat[i] = va_arg(args, const char *);
    }

    va_end(args);

    printTableStrings(rows, cols, mat); 
}


// fmta um inteiro
char* fmtInt(int x) {
    char* buffer = malloc(32); // espaço suficiente para qualquer int
    if (!buffer) return NULL;
    snprintf(buffer, 32, "%d", x);
    return buffer;
}

// fmta um ponteiro
char* fmtPtr(void* p) {
    char* buffer = malloc(32); 
    if (!buffer) return NULL;
    snprintf(buffer, 32, "%p", p);
    return buffer;
}

// fmta uma string (retorna uma cópia)
char* fmtStr(const char* s) {
    char* buffer = malloc(strlen(s) + 1);
    if (!buffer) return NULL;
    strcpy(buffer, s);
    return buffer;
}