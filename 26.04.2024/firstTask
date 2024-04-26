#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    
    printf("Enter the number of elements: ");
    scanf("%d", &N);

    FILE *file = fopen("binary_file.bin", "wb");
    if (file == NULL) {
        printf("Error!");
        return 1;
    }

    fwrite(&N, sizeof(int), 1, file);

    printf("Enter %d numbers:\n", N);
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, file);
    }
    fclose(file);

    return 0;
}
