#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    printf("N: ");
    scanf("%d", &n);
    printf("M: ");
    scanf("%d", &m);

    int array[n][m];

    for(int i = 0; i < n; i++){
        for(int j= 0; j < m; j++){
            scanf("%d", &array[i][j]);
        }
    }


    int rowsSort = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (array[i][j] < array[i][j - 1]) {
                rowsSort = 0;
                break;
            }
        }
    }

    int colsSort = 1;
    for (int j = 0; j < m; j++) {
        for (int i = 1; i < n; i++) {
            if (array[i][j] > array[i - 1][j]) {
                colsSort = 0;
                break;
            }
        }
    }

     if (rowsSort && colsSort) {
        printf("The arr is increasing in rows and columns.\n");
    } else {
        printf("The arr is not in correct order.\n");
    }





    return 0;
}
