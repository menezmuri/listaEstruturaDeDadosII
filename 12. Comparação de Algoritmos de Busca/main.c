#include <stdio.h>
#include <time.h>

// Função Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Função Interpolation Search
int interpolationSearch(int arr[], int size, int key) {
    int low = 0, high = size - 1;
    while (low <= high && key >= arr[low] && key <= arr[high]) {
        int pos = low + ((key - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == key)
            return pos;
        else if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

// Função Jump Search
int jumpSearch(int arr[], int size, int key) {
    int step = sqrt(size);
    int prev = 0;

    while (arr[step] <= key && step < size) {
        prev = step;
        step += sqrt(size);
        if (step >= size)
            step = size;
    }

    for (int i = prev; i < step; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    int arr[1000];
    for (int i = 0; i < 1000; i++) {
        arr[i] = i;
    }
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 750;

    clock_t start, end;

    // Binary Search
    start = clock();
    binarySearch(arr, 0, size - 1, key);
    end = clock();
    printf("Binary Search: %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // Interpolation Search
    start = clock();
    interpolationSearch(arr, size, key);
    end = clock();
    printf("Interpolation Search: %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    // Jump Search
    start = clock();
    jumpSearch(arr, size, key);
    end = clock();
    printf("Jump Search: %lf ms\n", ((double)(end - start) / CLOCKS_PER_SEC) * 1000);

    return 0;
}
