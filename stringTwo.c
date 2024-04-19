#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    int counts[256] = {0};

    printf("String: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; i < strlen(str); ++i) {
        counts[(unsigned char)str[i]]++;
    }

    printf("Characters:\n");
    for (int i = 0; i < 256; ++i) {
        if (counts[i] > 0) {
            printf("'%c': %d\n", (char)i, counts[i]);
        }
    }

    return 0;
}
