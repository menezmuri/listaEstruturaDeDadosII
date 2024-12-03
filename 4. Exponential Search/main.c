#include <stdio.h>

// Função auxiliar: Busca Binária
int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Função de Exponential Search
int exponentialSearch(int arr[], int size, int target) {
    if (arr[0] == target)
        return 0;

    int range = 1;
    while (range < size && arr[range] <= target)
        range *= 2;

    return binarySearch(arr, range / 2, fmin(range, size - 1), target);
}

int main() {
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 50;

    int result = exponentialSearch(arr, size, target);
    if (result != -1)
        printf("Elemento encontrado no índice %d.\n", result);
    else
        printf("Elemento não encontrado.\n");
    return 0;
}
