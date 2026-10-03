# Heap Sort in C

An implementation of the Heap Sort algorithm in C, with execution time measurement.

## Features

- Max-heap based sorting (`heapify` + `heapSort`)
- Sorts a list of 100,000 integers
- Three input types to compare behavior:
  - Random list
  - Already sorted list
  - Reverse-ordered list
- Measures execution time in milliseconds using `clock()`
- Uses dynamic memory allocation (`malloc` / `free`)

## How to run

```bash
gcc heap_sort.c -o heap_sort
./heap_sort
```

On Windows (MinGW):

```bash
gcc heap_sort.c -o heap_sort.exe
heap_sort.exe
```

## Example

```
=========================================
        TESTADOR DE HEAP SORT
        Tamanho da lista: 100000
=========================================
Escolha o tipo de entrada para testar:
1 - Gerar lista ALEATORIA
2 - Gerar lista JA ORDENADA
3 - Gerar lista ORDEM INVERSA
Opcao: 1
```

## Complexity

| Case | Time |
|------|------|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

Space complexity: O(log n) in this version, because `heapify` is recursive.

## Author

Haroldo Diógenes, Software Engineering student at IFCE.
