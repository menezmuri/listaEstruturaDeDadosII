#include <stdio.h>
#include <stdlib.h>

// Função auxiliar para ordenar baldes
void insertionSort(float arr[], int size) {
    for (int i = 1; i < size; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Função Bucket Sort
void bucketSort(float arr[], int size) {
    // Criação dos baldes
    int numBuckets = 10;
    float buckets[numBuckets][size];
    int count[numBuckets];
    for (int i = 0; i < numBuckets; i++) count[i] = 0;

    // Distribui os elementos nos baldes
    for (int i = 0; i < size; i++) {
        int idx = arr[i] * numBuckets;
        buckets[idx][count[idx]++] = arr[i];
    }

    // Ordena os baldes
    for (int i = 0; i < numBuckets; i++) {
        insertionSort(buckets[i], count[i]);
    }

    // Combina os baldes
    int idx = 0;
    for (int i = 0; i < numBuckets; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[idx++] = buckets[i][j];
        }
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size);

    printf("Array ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
