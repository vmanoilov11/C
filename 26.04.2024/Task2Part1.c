#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;

    FILE *file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        printf("Error!");
        return 1;
    }

    printf("Enter nums:\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        fwrite(&num, sizeof(int), 1, file);
    }

    fclose(file);

    printf("File created");

    return 0;
}
