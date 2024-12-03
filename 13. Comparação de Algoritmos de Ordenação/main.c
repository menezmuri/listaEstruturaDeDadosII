#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Função de troca
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Algoritmo de Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIdx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(&arr[i], &arr[minIdx]);
    }
}

// Algoritmo de Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Algoritmo de Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função principal para comparação de tempos
int main() {
    int arr1[1000], arr2[1000], arr3[1000];
    for (int i = 0; i < 1000; i++) {
        arr1[i] = rand() % 1000;
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }

    int size = sizeof(arr1) / sizeof(arr1[0]);

    // Seleção
    clock_t start, end;
    start = clock();
    selectionSort(arr1, size);
    end = clock();
    printf("Selection Sort: %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // Merge Sort
    start = clock();
    mergeSort(arr2, 0, size - 1);
    end = clock();
    printf("Merge Sort: %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // Quick Sort
    start = clock();
    quickSort(arr3, 0, size - 1);
    end = clock();
    printf("Quick Sort: %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    return 0;
}
