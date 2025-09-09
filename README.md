# Trabalho de Ponteiros em C

## Descrição

Este trabalho explora os conceitos fundamentais de ponteiros em C, aplicando-os em exemplos práticos e demonstrando sua importância para:

- Declaração e uso básico de ponteiros.
- Aritmética de ponteiros em arrays e strings.
- Alocação dinâmica de memória com `malloc`/`free`.
- Passagem de parâmetros por referência e ponteiros para ponteiros.
- Uso de ponteiros para funções (exemplo com `qsort` e `bubble_sort`).
- Identificação de armadilhas comuns (ponteiro selvagem, dangling pointer, double free, etc.).

Todos os códigos foram comentados detalhadamente, mostrando como cada conceito funciona na prática.

---

## Conteúdo do Repositório

- `src/` → arquivos-fonte dos exemplos.
- `src/utils/` → funções utilitárias para impressão tabular.
- `README.md` → explicações teóricas e instruções de uso.

---

## Conceitos Demonstrados

### 1. Uso de `&` (address-of) e `*` (dereference)

```c
int x = 42;
int *p = &x;
```

- `&x` → endereço de `x`
- `*p` → valor armazenado no endereço apontado
- Permite alterar a variável original através do ponteiro.

**Saída esperada:**

```
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
```

---

### 2. Relação entre Arrays e Ponteiros

```c
int a[5] = {10, 20, 30, 40, 50};
int *p = a;
```

- `a[i]` ≡ `*(p+i)`
- `p+1` avança `sizeof(int)` bytes
- Permite percorrer arrays usando ponteiros.

**Saída esperada:**

```
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
```

---

### 3. Diferença entre `char s[]` e `const char *`

```c
char s1[] = "hello";
const char *s2 = "world";
```

- `s1` pode ser modificado (`s1[0] = 'H'`)
- `s2` não pode alterar o literal, mas pode apontar para outro literal (`s2 = "World"`)

**Saída esperada:**

```
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
```

---

### 4. Função Swap com Ponteiros

```c
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
```

- Permite trocar valores de variáveis fora da função
- Demonstra passagem por referência usando ponteiros.

**Saída esperada:**

```
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
```

---

### 5. Alocação Dinâmica de Memória

```c
int *arr;
size_t n = 5;
arr = malloc(n * sizeof *arr);
```

- `malloc` aloca memória em tempo de execução
- `free(arr);` libera a memória
- Permite criar arrays de tamanho variável, determinado em tempo de execução.

**Saída esperada:**

```
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
```

---

### 6. Ponteiro para Função

```c
int cmp_ints(const void *a, const void *b) { ... }
qsort(v, n, sizeof v[0], cmp_ints);
bubble_sort(v, n, cmp_ints);
```

- Funções podem ser passadas como ponteiros (`int (*cmp)(const void*, const void*)`)
- Permite criar funções de ordem maior, como ordenação (`qsort`, `bubble_sort`).

**Saída esperada:**

```
+--------+----+---+----+---+----+----+
| Antes  | 42 | 5 | 17 | 3 | 99 | 42 |
+--------+----+---+----+---+----+----+

+--------+---+---+----+----+----+----+
| Depois | 3 | 5 | 17 | 42 | 42 | 99 |
+--------+---+---+----+----+----+----+
```

---

## Cuidados e Armadilhas

- **Ponteiro selvagem**: ponteiro não inicializado.
- **Dangling pointer**: ponteiro apontando para memória liberada.
- **Double free**: chamar `free` duas vezes para o mesmo ponteiro.
- Sempre inicializar ponteiros e liberar memória corretamente.

---

## Compilação e Execução

### Compilação (Linux/WSL)

```bash
gcc src/ex1.c src/utils/table.c -o build/ex1
gcc src/ex2.c src/utils/table.c -o build/ex2
gcc src/ex3.c src/utils/table.c -o build/ex3
gcc src/ex4.c src/utils/table.c -o build/ex4
gcc src/ex5.c src/utils/table.c -o build/ex5
gcc src/ex6.c src/utils/table.c -o build/ex6
```

Ou usando a task do VS Code:

- Selecionar o arquivo ativo e executar **Ctrl+Shift+B** (Build Current Program)
- Binário gerado em `build/`

### Execução

```bash
./build/ex1
./build/ex2
./build/ex3
./build/ex4
./build/ex5
./build/ex6
```

---

## Dependências

- Compilador C (`gcc`)
- Biblioteca padrão do C (`stdlib.h`, `stdio.h`)
- Nenhuma biblioteca externa.

```

```
