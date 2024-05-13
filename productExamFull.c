#include <stdio.h>
#include <stdlib.h>

struct Product{
    char nameProduct[21];
    int id;
    char expireDate[11];
    float price;
};

float avrg_by_price(struct Product *products, int n, float price){
    float totalSum = 0;
    int count = 0;
    for(int i = 0; i < n; i++){
        if(products[i].price < price){
            totalSum += products[i].price;
            count++;
        }
    }
    return totalSum / count;
}

void write_text_file(struct Product *products, int n, char *date, float price){
    int year, month, day;
    sscanf(date, "%s%d%d%d", date &year, &month, &day);

    FILE *file = fopen("products.txt", "w");

    if(file == NULL){
        printf("Error!");
        return -1;
    }

    int count = 0;
    for(int i=0; i < n; i++){
            int yearOfProduct, monthOfProduct, dayOfProduct;
            sscanf(products[i].expireDate, "%s%d%d%d", products[i].expireDate &yearOfProduct, &monthOfProduct, &dayOfProduct);
            if(yearOfProduct < year || monthOfProduct < month || dayOfProduct < day){
                if(products[i].price > price){
                    count++;
                    fprintf(file, "%s-%d-%s-%f lv\n.",products[i].nameProduct, products[i].id, products[i].expireDate, products[i].price)
                }
            }
    }
    fclose(file);
    return count;

}
void print_info(char name, int code){
    FILE *file = fopen("product.bin", "rb");
    if (file == NULL) {
        return 0;
    }
    struct Product product;
    while(fread(&product,sizeof(struct Product),1, file) == 1){
        if(product.name == name && product.id == code){
            printf("Име на продукт: %s\n", product.name);
            printf("Уникален код: %03d\n", product.id);
            printf("Срок на годност: %s\n", product.expireDate);
            printf("Цена: %.2f лв.\n", product.price);
            found = 1;
            break;
        }
    }
    if(!found){
        printf("Не е открито съвпадение за продукт");
    }
    fclose(file);
}

int main(){
    int n;
    printf("Enter N: ");
    scanf("%d", &n);

    if(10> n || n > 30){
        printf("Invalid number");
        return 1;
    }

    struct Product *products = (struct Product *)malloc(n * sizeof(struct Product));
    if(products == NULL){
        printf("Error memory allocation!");
        return 1;
    }

    for(int i= 0; i < n; i++){
        printf("Info for product number %d\n", i + 1);
        printf("Enter name of product: ");
        scanf("%s", products[i].nameProduct);

        printf("Enter id of product: ");
        scanf("%d", &products[i].id);

        printf("Enter expire date of product: ");
        scanf("%s", products[i].expireDate);

        printf("Enter price of product: ");
        scanf("%f", &products[i].price);

    }

    float price;
    printf("Enter price: ");
    scanf("%f", &price);

    float result = avrg_by_price(products, n, price);

    char date[11];
    printf("Enter date to look for: ");
    scanf("%s", date);
    int count = write_text_file(products, n, date, price);
    printf("%d", count);

    char nameToLook[21];
    printf("Enter name to look for: ");
    scanf("%s", nameToLook);
    int codeToLook;
    printf("Enter Code to look for: ");
    scanf("%d", &codeToLook);

    print_info(*nameToLook, codeToLook);

    free(products);
return 0;
}
