#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para manter a propriedade de Max-Heap
void heapify(int arr[], int n, int i) {
    int maior = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && arr[esquerda] > arr[maior])
        maior = esquerda;

    if (direita < n && arr[direita] > arr[maior])
        maior = direita;

    if (maior != i) {
        int temp = arr[i];
        arr[i] = arr[maior];
        arr[maior] = temp;
        heapify(arr, n, maior);
    }
}

// Função principal do Heap Sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int opcao;
    int n = 100000; // Tamanho fixo de 100.000 elementos
    
    // Alocação dinâmica para evitar estouro de memória (Stack Overflow)
    int *arr = (int*) malloc(n * sizeof(int));
    
    // Inicializa a semente para geração de números aleatórios
    srand(time(NULL));

    printf("=========================================\n");
    printf("        TESTADOR DE HEAP SORT\n");
    printf("        Tamanho da lista: %d\n", n);
    printf("=========================================\n");
    printf("Escolha o tipo de entrada para testar:\n");
    printf("1 - Gerar lista ALEATORIA\n");
    printf("2 - Gerar lista JA ORDENADA\n");
    printf("3 - Gerar lista ORDEM INVERSA\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Preenche o vetor de 100.000 posições dependendo da escolha
    if (opcao >= 1 && opcao <= 3) {
        for(int i = 0; i < n; i++) {
            if (opcao == 1) {
                arr[i] = rand() % 1000000; // Números aleatórios até 999.999
            } else if (opcao == 2) {
                arr[i] = i; // Já ordenado: 0, 1, 2, 3...
            } else if (opcao == 3) {
                arr[i] = n - i; // Ordem Inversa: 100000, 99999, 99998...
            }
        }
        printf("\nVetor de %d elementos gerado na memoria!\n", n);
    } 
    else {
        printf("Opcao invalida!\n");
        free(arr);
        return 1;
    }

    // ==========================================
    // MEDIÇÃO DE TEMPO
    // ==========================================
    printf("Ordenando...\n");
    
    clock_t inicio = clock();
    
    heapSort(arr, n);
    
    clock_t fim = clock();
    
    double tempo_execucao = ((double)(fim - inicio) / CLOCKS_PER_SEC) * 1000.0;

    printf("(Vetor ordenado com sucesso. Impressao oculta devido ao tamanho da lista).\n");

    printf("\n=========================================\n");
    printf("TEMPO DE EXECUCAO: %.4f milissegundos\n", tempo_execucao);
    printf("=========================================\n");

    free(arr);

    return 0;
}