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

Vetor de 100000 elementos gerado na memoria!
Ordenando...
(Vetor ordenado com sucesso. Impressao oculta devido ao tamanho da lista).

=========================================
TEMPO DE EXECUCAO: 28.5910 milissegundos
=========================================
```

## Benchmark results

Sorting 100,000 integers:

| Input type | Execution time |
|------------|----------------|
| Random | ~28.6 ms |
| Already sorted | ~23.2 ms |
| Reverse order | ~22.5 ms |

Heap Sort is O(n log n) in all cases, so the three times are close. The random input is slightly slower, likely because of less predictable memory access patterns (cache behavior).

*Results measured on my machine (Linux). Times vary between runs and hardware.*

## Complexity

| Case | Time |
|------|------|
| Best | O(n log n) |
| Average | O(n log n) |
| Worst | O(n log n) |

Space complexity: O(log n) in this version, because `heapify` is recursive. An iterative `heapify` would reduce it to O(1).

## Possible improvements

- Make the list size configurable by the user
- Rewrite `heapify` iteratively to reduce space usage
- Compare with other algorithms (Quick Sort, Merge Sort)
- Translate the program messages to English

## Author

Haroldo Diógenes, Software Engineering student at IFCE (Federal Institute of Ceará, Brazil).
