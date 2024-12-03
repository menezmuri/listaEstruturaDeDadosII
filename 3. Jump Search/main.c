#include <stdio.h>
#include <math.h>

// Função de Jump Search
int jumpSearch(int arr[], int size, int target) {
    int step = sqrt(size); // Tamanho ideal do salto
    int prev = 0;

    // Encontrar o bloco onde o elemento pode estar
    while (arr[fmin(step, size) - 1] < target) {
        prev = step;
        step += sqrt(size);
        if (prev >= size)
            return -1;
    }

    // Busca linear dentro do bloco
    for (int i = prev; i < fmin(step, size); i++) {
        if (arr[i] == target)
            return i;
    }

    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 13;

    int result = jumpSearch(arr, size, target);
    if (result != -1)
        printf("Elemento encontrado no índice %d.\n", result);
    else
        printf("Elemento não encontrado.\n");
    return 0;
}
