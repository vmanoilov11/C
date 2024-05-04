#include <stdio.h>
#include <string.h>

struct IceCream{
    char code[3];
    char name[21];
    int weight;
    double price;
};

double calculate(struct IceCream iceCreams[], int n, char letter){
    double totalPrice = 0;

    for(int i = 0; i < n; i++){
        if(iceCreams[i].name[0] == letter){
            totalPrice += iceCreams[i].price * iceCreams[i].weight;
        }

    }
    return totalPrice;

}

int main() {
    struct IceCream iceCreams[] = {
        {"A1", "Vanilla", 2, 5.0},
        {"B2", "Chocolate", 3, 6.5},
        {"C3", "Strawberry", 1, 4.0}
    };
    int n = sizeof(iceCreams) / sizeof(iceCreams[0]);

    char letter;
    printf("Enter letter: ");
    scanf(" %c", &letter);


    double totalPrice = calculate(iceCreams, n, letter);

    if(totalPrice > 0){
            printf("Total price: %0.2lf", totalPrice);

    }else{
        printf("No ice starting with '%c'\n", letter);
        return 0;
        }

    return 0;

}
