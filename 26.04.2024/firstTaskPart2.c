#include <stdio.h>

int main() {
    int N;
    printf("N: ");
    scanf("%d", &N);

    FILE *file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        printf("Error!");
        return 1;
    }

    fseek(file, sizeof(int), SEEK_SET);

    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < N; i++) {
        int num;
        fread(&num, sizeof(int), 1, file);
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    fclose(file);

    printf("Even nums: %d\n", evenCount);
    printf("Odd nums: %d\n", oddCount);

    return 0;
}
