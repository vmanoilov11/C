#include <stdio.h>

int main() {
    int n;
    printf("N: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    int longestSequenceStart = 0;
    int longestSequenceLength = 1;
    int currentSequenceStart = 0;
    int currentSequenceLength = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] == arr[i - 1]){
            currentSequenceLength++;
        } else {
            if(currentSequenceLength > longestSequenceLength){
                longestSequenceLength = currentSequenceLength;
                longestSequenceStart = currentSequenceStart;
            }
            currentSequenceLength = 1;
            currentSequenceStart = i;
        }
    }
    if(currentSequenceLength > longestSequenceLength){
        longestSequenceLength = currentSequenceLength;
        longestSequenceStart = currentSequenceStart;
    }

    printf("Biggest sequence: ");
    for(int i = longestSequenceStart; i < longestSequenceStart + longestSequenceLength; i++){
        printf("%d ", arr[i]);
    }
    printf("\nLength: %d\n", longestSequenceLength);

    return 0;
}
