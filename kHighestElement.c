#include <stdio.h>
int main() {
    int k, n;
    int temp;
    printf("N: ");
    scanf("%d", &n);

    printf("K: ");
    scanf("%d", &k);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    for(int i=0; i<n; i++){
        for(int j= i+1; j < n; j++){
                if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("%d", arr[n - k]);

    return 0;
}
