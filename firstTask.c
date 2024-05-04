#include <stdio.h>

void sortDescending(int *a, int *b, int *c);

int main() {
    int num1, num2, num3;

    printf("Въведет първото число: ");
    scanf("%d", &num1);
    printf("Въведете второто число: ");
    scanf("%d", &num2);
    printf("Въведете третото число: ");
    scanf("%d", &num3);

 
    sortDescending(&num1, &num2, &num3);

    printf("Сортирани в низходящ ред: %d %d %d\n", num1, num2, num3);

    return 0;
}

void sortDescending(int *a, int *b, int *c) {
    int temp;

    if (*a < *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
    if (*b < *c) {
        temp = *b;
        *b = *c;
        *c = temp;
    }
    if (*a < *b) {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}
