#include <stdio.h>
#include <stdlib.h>

#define FILENAME "numbers.bin"

int main() {
    FILE *fp;
    int n, num;
    int even_count = 0, odd_count = 0;

    fp = fopen(FILENAME, "rb");
    if (fp == NULL) {
        printf("Error!.\n");
        return 1;
    
    fread(&n, sizeof(int), 1, fp);

    for (int i = 0; i < n; i++) {
        fread(&num, sizeof(int), 1, fp);
        if (num % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    fclose(fp);

    printf("Even nums count: %d\n", even_count);
    printf("Odd nums count: %d\n", odd_count);

    return 0;
}
