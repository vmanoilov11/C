#include <stdio.h>
#include <stdlib.h>

struct IceCream {
    char code[3];
    char name[20];
    int weight;
    double price;
};

int main() {
    int n;
    printf("Enter a number (between 5 and 15): ");
    scanf("%d", &n);

    if (n < 5 || n > 15) {
        printf("Invalid number!\n");
        return 1;
    }

    struct IceCream *iceCreams = (struct IceCream *)malloc(n * sizeof(struct IceCream));
    if (iceCreams == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Information for ice cream %d\n", i + 1);

        printf("Code: ");
        scanf("%s", iceCreams[i].code);

        printf("Name: ");
        scanf("%s", iceCreams[i].name);

        printf("Weight: ");
        scanf("%d", &iceCreams[i].weight);

        printf("Price per kg: ");
        scanf("%lf", &iceCreams[i].price);
    }

    printf("\nIce Cream Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Ice Cream %d:\n", i + 1);
        printf("Code: %s\n", iceCreams[i].code);
        printf("Name: %s\n", iceCreams[i].name);
        printf("Weight: %d\n", iceCreams[i].weight);
        printf("Price per kg: %.2lf\n", iceCreams[i].price);
        printf("\n");
    }

    free(iceCreams);

    return 0;
}
