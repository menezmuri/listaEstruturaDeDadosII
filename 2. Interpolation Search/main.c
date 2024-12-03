#include <stdio.h>

// Função de busca por interpolação
int interpolationSearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) 
                return low;
            return -1;
        }

        // Fórmula de interpolação
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (target - arr[low]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 70;

    int result = interpolationSearch(arr, size, target);
    if (result != -1) 
        printf("Elemento encontrado no índice %d.\n", result);
    else 
        printf("Elemento não encontrado.\n");
    return 0;
}
