#include <stdio.h>
#include <stdlib.h>

// Função para realizar o Bucket Sort
void bucketSort(float arr[], int n) {
    if (n <= 0) return;
    
    // Cria os baldes
    float **buckets = malloc(n * sizeof(float*));
    int *bucketSizes = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        buckets[i] = malloc(n * sizeof(float));
        bucketSizes[i] = 0;
    }

    // Distribui os elementos nos baldes
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] * n;  // Considerando que arr[i] está entre [0, 1)
        buckets[bucketIndex][bucketSizes[bucketIndex]++] = arr[i];
    }

    // Ordena os elementos de cada balde
    for (int i = 0; i < n; i++) {
        qsort(buckets[i], bucketSizes[i], sizeof(float), compareFloat);
    }

    // Junta todos os elementos ordenados dos baldes
    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bucketSizes[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }

    // Libera a memória dos baldes
    for (int i = 0; i < n; i++) {
        free(buckets[i]);
    }
    free(buckets);
    free(bucketSizes);
}

// Função de comparação para qsort
int compareFloat(const void *a, const void *b) {
    return (*(float*)a > *(float*)b) - (*(float*)a < *(float*)b);
}

// Função de Interpolation Search
int interpolationSearch(float arr[], int n, float target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;  // Elemento não encontrado
}

int main() {
    float scores[] = {0.12, 0.59, 0.74, 0.88, 0.35, 0.26, 0.45};  // Notas dos alunos
    int n = sizeof(scores) / sizeof(scores[0]);

    // Ordena as notas com Bucket Sort
    bucketSort(scores, n);

    printf("Notas ordenadas: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", scores[i]);
    }
    printf("\n");

    // Busca uma nota específica com Interpolation Search
    float target = 0.35;
    int result = interpolationSearch(scores, n, target);

    if (result != -1) {
        printf("Nota %.2f encontrada no índice %d\n", target, result);
    } else {
        printf("Nota %.2f não encontrada.\n", target);
    }

    return 0;
}
