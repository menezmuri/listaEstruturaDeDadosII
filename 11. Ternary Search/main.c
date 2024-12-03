#include <stdio.h>

// Função Ternary Search recursiva
int ternarySearch(int arr[], int low, int high, int key) {
    if (low <= high) {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }

        if (key < arr[mid1]) {
            return ternarySearch(arr, low, mid1 - 1, key);
        } else if (key > arr[mid2]) {
            return ternarySearch(arr, mid2 + 1, high, key);
        } else {
            return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    int result = ternarySearch(arr, 0, size - 1, key);
    if (result != -1) {
        printf("Elemento %d encontrado no índice %d.\n", key, result);
    } else {
        printf("Elemento %d não encontrado.\n", key);
    }

    return 0;
}
