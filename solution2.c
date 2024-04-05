#include <stdio.h>

int main() {
    int nums[10];
    int frequency[10001] = {0};

    printf("Input nums, for end type 9999:\n");

    int num, count = 0;
    while (count < 10) {
        scanf("%d", &num);
        if (num == 9999) {
            break;
        }
        if (num >= -5000 && num <= 5000) {
            nums[count++] = num;
            frequency[num + 5000]++;
        } else {
            printf("Error!\n");
        }
    }

    printf("Frequency:\n");
    for (int i = 0; i < count; i++) {
        printf("%d: %d times.\n", nums[i], frequency[nums[i] + 5000]);
    }

    return 0;
}
