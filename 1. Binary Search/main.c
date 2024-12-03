#include <stdio.h>

// Função de busca binária
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) 
            return mid; // Retorna o índice do elemento
        else if (arr[mid] < target) 
            left = mid + 1;
        else 
            right = mid - 1;
    }
    return -1; // Elemento não encontrado
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 72};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);
    if (result != -1) 
        printf("Elemento encontrado no índice %d.\n", result);
    else 
        printf("Elemento não encontrado.\n");
    return 0;
}
