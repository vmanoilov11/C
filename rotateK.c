#include <stdio.h>

void change(int arr[], int n, int k) {
    int temp;

    for (int i = 0; i < k; i++) {
        temp = arr[n - 1];

        for (int j = n - 1; j > 0; j--) {
            arr[j] = arr[j - 1];
        }
        arr[0] = temp;
    }
}

int main() {
    int k, n;
    printf("N: ");
    scanf("%d", &n);

    printf("K: ");
    scanf("%d", &k);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    change(arr, n, k);

    printf("Array after rotation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
