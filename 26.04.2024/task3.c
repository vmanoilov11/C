#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MODEL_LENGTH 6
#define DATABASE_FILE "cars.bin"
#define TEXT_DATABASE_FILE "cars.txt"

// Структура за автомобил
struct Car {
    char brand[50];
    char model[MAX_MODEL_LENGTH];
    float engineVolume;
    float price;
    char hasRegistration;
};

// Функция за добавяне на нов запис в базата данни
void addCar(struct Car *car) {
    FILE *fp = fopen(DATABASE_FILE, "ab");
    if (fp == NULL) {
        printf("Error opening database file!\n");
        return;
    }

    fwrite(car, sizeof(struct Car), 1, fp);

    fclose(fp);
}

// Функция за запис на данни в текстов файл
void saveTextDatabase() {
    FILE *binaryFp = fopen(DATABASE_FILE, "rb");
    FILE *textFp = fopen(TEXT_DATABASE_FILE, "w");

    if (binaryFp == NULL || textFp == NULL) {
        printf("Error opening files!\n");
        return;
    }

    struct Car car;
    while (fread(&car, sizeof(struct Car), 1, binaryFp)) {
        fprintf(textFp, "Brand: %s, Model: %s, Engine Volume: %.2f, Price: %.2f, Registration: %c\n",
                car.brand, car.model, car.engineVolume, car.price, car.hasRegistration);
    }

    fclose(binaryFp);
    fclose(textFp);
}

// Функция за прочитане на данни от базата данни и извеждане на екрана
void displayDatabase() {
    FILE *fp = fopen(DATABASE_FILE, "rb");
    if (fp == NULL) {
        printf("Error opening database file!\n");
        return;
    }

    printf("Cars in the database:\n");
    struct Car car;
    while (fread(&car, sizeof(struct Car), 1, fp)) {
        printf("Brand: %s, Model: %s, Engine Volume: %.2f, Price: %.2f, Registration: %c\n",
                car.brand, car.model, car.engineVolume, car.price, car.hasRegistration);
    }

    fclose(fp);
}

int main() {
    struct Car car;

    // Примерен запис на автомобил в базата данни
    strcpy(car.brand, "Toyota");
    strcpy(car.model, "Camry");
    car.engineVolume = 2.5;
    car.price = 25000.00;
    car.hasRegistration = 'Y';

    // Добавяне на автомобила в базата данни
    addCar(&car);

    // Запис на данните от базата данни в текстов файл
    saveTextDatabase();

    // Извеждане на данните от базата данни на екрана
    displayDatabase();

    return 0;
}
