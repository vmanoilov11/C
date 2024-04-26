#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    printf("N: ");
    scanf("%d", &N);

    FILE *binFile = fopen("numbers.bin", "rb");
    if (binFile == NULL) {
        printf("Error!");
        return 1;
    }

    fseek(binFile, sizeof(int), SEEK_SET);

    int *array = (int *)malloc(N * sizeof(int));
    if (array == NULL) {
        printf("Failed!");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fread(&array[i], sizeof(int), 1, binFile);
    }

    fclose(binFile);

    qsort(array, N, sizeof(int), compare);

    FILE *textFile = fopen("sorted_numbers.txt", "w");
    if (textFile == NULL) {
        printf("Error!");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fprintf(textFile, "%d ", array[i]);
    }

    fclose(textFile);
    free(array);

    return 0;
}
