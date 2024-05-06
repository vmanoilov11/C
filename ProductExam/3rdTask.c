int write_text_file(struct Product *products, int size, char *date, float price) {
    FILE *file = fopen("products.txt", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return -1; 
    }

    int count = 0; 

    for (int i = 0; i < size; i++) {
        if (strcmp(products[i].expirationDate, date) < 0 && products[i].price > price) {
            fprintf(file, "%s - %d - %s - %.2fлв.\n", products[i].name, products[i].code, products[i].expirationDate, products[i].price);
            count++;
        }
    }

    fclose(file);
    return count;
}


char date[11] = "2023.05.25"; 
    float price = 10.00; 

    int result = write_text_file(products, n, date, price);

    if (result == -1) {
        printf("Error writing to file.\n");
    } else if (result == 0) {
        printf("No matching products found.\n");
    } else {
        printf("Successfully wrote %d products to file.\n", result);
    }
