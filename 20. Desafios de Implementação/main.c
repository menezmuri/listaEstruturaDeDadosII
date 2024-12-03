#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para realizar a busca binária
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Função para realizar o Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void chooseAlgorithm() {
    int option;
    printf("Escolha o algoritmo:\n");
    printf("1. Busca Binária\n");
    printf("2. Ordenação (Quick Sort)\n");
    printf("Digite sua opção: ");
    scanf("%d", &option);

    int arr[] = {10, 30, 50, 70, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    if (option == 1) {
        int target;
        printf("Digite o valor para buscar: ");
        scanf("%d", &target);
        int result = binarySearch(arr, size, target);
        if (result != -1) {
            printf("Elemento encontrado no índice %d.\n", result);
        } else {
            printf("Elemento não encontrado.\n");
        }
    } else if (option == 2) {
        printf("Antes da ordenação: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        quickSort(arr, 0, size - 1);
        printf("\nApós a ordenação: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Opção inválida.\n");
    }
}

int main() {
    chooseAlgorithm();
    return 0;
}
