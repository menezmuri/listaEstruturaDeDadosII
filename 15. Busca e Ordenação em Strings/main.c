#include <stdio.h>
#include <string.h>

// Função para comparar duas strings
int compareStrings(const void* a, const void* b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

// Função para ordenar uma lista de strings usando Quick Sort
void quickSortStrings(char* arr[], int low, int high) {
    if (low < high) {
        int pi = partitionStrings(arr, low, high);
        quickSortStrings(arr, low, pi - 1);
        quickSortStrings(arr, pi + 1, high);
    }
}

// Função para particionar o array de strings
int partitionStrings(char* arr[], int low, int high) {
    char* pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (strcmp(arr[j], pivot) < 0) {
            i++;
            swapStrings(&arr[i], &arr[j]);
        }
    }
    swapStrings(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Função para trocar duas strings
void swapStrings(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    char* arr[] = {"banana", "apple", "cherry", "date"};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Ordenar usando Quick Sort
    quickSortStrings(arr, 0, size - 1);

    printf("Strings ordenadas: ");
    for (int i = 0; i < size; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    return 0;
}
