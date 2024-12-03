#include <stdio.h>
#include <stdlib.h>

// Função Binary Search
int binarySearch(int arr[], int size, int target) {
    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;  // Encontrou o ISBN
        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // Não encontrado
}

int main() {
    int books[] = {12345, 23456, 34567, 45678, 56789, 67890}; // Lista de ISBNs ordenada
    int size = sizeof(books) / sizeof(books[0]);
    int targetISBN = 34567;

    int result = binarySearch(books, size, targetISBN);
    if (result != -1) {
        printf("Livro encontrado no índice %d\n", result);
    } else {
        printf("Livro com ISBN %d não encontrado.\n", targetISBN);
    }

    return 0;
}
