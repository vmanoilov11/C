#include <stdio.h>
#include <stdlib.h>

struct Product {
    char name[21];
    int code;
    char expirationDate[11];
    float price;
};

float avrg_by_price(struct Product *products, int n, float price) {
    int count = 0;
    float sum = 0;

    for (int i = 0; i < n; i++) {
        if (products[i].price < price) {
            sum += products[i].price;
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    return sum / count;
}

int main() {
    int n;
    printf("Enter the number of products (between 11 and 29): ");
    scanf("%d", &n);

    if (n < 10 || n > 30) {
        printf("Invalid input for the number of products.\n");
        return 1;
    }

    struct Product *products = (struct Product *)malloc(n * sizeof(struct Product));
    if (products == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Product %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", products[i].name);

        printf("Code: ");
        scanf("%d", &products[i].code);

        printf("Expiration Date (YYYY.MM.DD): ");
        scanf("%s", products[i].expirationDate);

        printf("Price: ");
        scanf("%f", &products[i].price);
    }

    float inputPrice;
    printf("Enter a price to calculate the average for products with price lower than it: ");
    scanf("%f", &inputPrice);

    float average = avrg_by_price(products, n, inputPrice);
    if (average == 0) {
        printf("No products found with price lower than %.2f\n", inputPrice);
    } else {
        printf("Average price for products with price lower than %.2f: %.2f\n", inputPrice, average);
    }

    free(products);

    return 0;
}

