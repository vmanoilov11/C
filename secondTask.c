#include <stdio.h>
#include <limits.h>

int findMax(int numbers[], int count);
int findMin(int numbers[], int count);
int calculateSum(int numbers[], int count);
float calculateAverage(int sum, int count);
int calculateDifference(int max, int min);

int main() {
    int numbers[100]; 
    int count = 0;
    int number;

    do {
        printf("Въведете число (или 0 за край): ");
        scanf("%d", &number);
        if (number != 0) {
            numbers[count++] = number;
        }
    } while (number != 0);

    int max = findMax(numbers, count);
    int min = findMin(numbers, count);
    int sum = calculateSum(numbers, count);
    float average = calculateAverage(sum, count);
    int difference = calculateDifference(max, min);

    printf("Най-голямото число: %d\n", max);
    printf("Най-малкото число: %d\n", min);
    printf("Сумата на въведените числа: %d\n", sum);
    printf("Средноаритметичното на въведените числа: %.2f\n", average);
    printf("Разликата e: %d\n", difference);

    return 0;
}
int findMax(int numbers[], int count) {
    int max = INT_MIN;
    for (int i = 0; i < count; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}
int findMin(int numbers[], int count) {
    int min = INT_MAX;
    for (int i = 0; i < count; i++) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return min;
}

int calculateSum(int numbers[], int count) {
    int sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    return sum;
}

float calculateAverage(int sum, int count) {
    if (count == 0) {
        return 0; // Избягваме деление на нула
    }
    return (float) sum / count;
}

int calculateDifference(int max, int min) {
    return max - min;
}
