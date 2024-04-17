#include <stdio.h>

int main() {
    int n, m;
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);

    int array[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    int smallest = array[0][0];
    int smallRow = 0;
    int biggest = array[0][0];
    int bigRow = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (smallest > array[i][j]) {
                smallest = array[i][j];
                smallRow = i;
            }
            if(biggest < array[i][j]){
                biggest = array[i][j];
                bigRow = i;
            }
        }
    }

    printf("Smallest = %d\n", smallest);
    printf("biggest = %d\n", biggest);

    for (int j = 0; j < m; j++) {
            int temp = array[smallRow][j];
            array[smallRow][j] = array[bigRow][j];
            array[bigRow][j] = temp;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
             printf("%d ", array[i][j]);
        }
        printf("\n");
    }


    return 0;
