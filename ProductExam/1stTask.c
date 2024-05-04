#include <stdio.h>
#include <stdlib.h>

struct Product {
    char name[20];
    int code;
    char date[11];
    float price;
};

int main() {
    int n;
    printf("Enter n (between 10 and 30): ");
    if (scanf("%d", &n) != 1 || n < 10 || n > 30) {
        printf("Invalid input for n!\n");
        return 1;
    }

    struct Product *products = (struct Product *)malloc(n * sizeof(struct Product));
    if (products == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Type information for product %d:\n", i + 1);

        printf("Name: ");
        if (scanf("%19s", products[i].name) != 1) {
            printf("Invalid input for name!\n");
            return 1;
        }

        printf("Code: ");
        if (scanf("%d", &products[i].code) != 1) {
            printf("Invalid input for code!\n");
            return 1;
        }

        printf("Date (YYYY.MM.DD): ");
        if (scanf("%10s", products[i].date) != 1) {
            printf("Invalid input for date!\n");
            return 1;
        }

        printf("Price: ");
        if (scanf("%f", &products[i].price) != 1) {
            printf("Invalid input for price!\n");
            return 1;
        }
    }

    printf("Product information input complete.\n");

    free(products);

    return 0;
}
