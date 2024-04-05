#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void inputNumbers(int numbers[]);
int calculateSum(int numbers[]);
int maxNum(int numbers[]);
float calculateAverage(int sum);
float closestNum(float avg, int numbers[]);

int main() {
    int numbers[7];
    inputNumbers(numbers);

    int sum = calculateSum(numbers);
    int max = maxNum(numbers);
    float avg = calculateAverage(sum);
    float closest = closestNum(avg, numbers);

    printf("Sum: %d\n", sum);
    printf("Max num: %d\n", max);
    printf("Average num: %f\n", avg);
    printf("Closest num: %f\n", closest);

    return 0;
}

void inputNumbers(int numbers[]) {
    printf("Type 7 nums[-5000, 5000]:\n");
    for (int i = 0; i < 7; i++) {
        scanf("%d", &numbers[i]);
    }
}

int calculateSum(int numbers[]) {
    int sum = 0;
    for (int i = 0; i < 7; i++) {
        sum += numbers[i];
    }
    return sum;
}
int maxNum(int numbers[]) {
    int max = INT_MIN;
    for (int i = 0; i < 7; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    return max;
}

float calculateAverage(int sum) {
    return (float)sum / 7;
}

float closestNum(float avg, int numbers[]) {
    float closest = numbers[0];
    float minDiff = fabs(avg - numbers[0]);
    for (int i = 1; i < 7; i++) {
        float diff = fabs(avg - numbers[i]);
        if (diff < minDiff) {
            minDiff = diff;
            closest = numbers[i];
        }
    }
    return closest;
}
