#include <stdio.h>

int main() {
    int n, counter = 1;
    int rowLength = 1;
    printf("N: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1] + 1){
            counter++;
            if(counter > rowLength){
                rowLength = counter;
            }
        }else{
            counter = 1;
        }
    }

    printf("%d", rowLength);

    return 0;
}
