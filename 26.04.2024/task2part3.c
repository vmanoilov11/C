#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[MAX_SIZE];
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    FILE *fp = fopen("sorted_array.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d ", arr[i]);
    }

    fclose(fp);

    return 0;
}
