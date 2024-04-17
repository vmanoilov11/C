#include <stdio.h>

int main() {
    int maxRows = 100;
    int maxCols = 100;
    int matrix[maxRows][maxCols];
    int N, M;

    printf("Rows (N): ");
    scanf("%d", &N);
    printf("Columns (M): ");
    scanf("%d", &M);

    printf("Matrix elements:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int maxSum = -1;
    int maxNum = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int sum = 0;
            for (int row = i - 1; row <= i + 1; row++) {
                for (int col = j - 1; col <= j + 1; col++) {
                    if (row >= 0 && row < N && col >= 0 && col < M) {
                        sum += matrix[row][col];
                    }
                }
            }
            sum -= matrix[i][j];
            if (sum > maxSum) {
                maxSum = sum;
                maxNum = matrix[i][j];
            }
        }
    }

    printf("Num is : %d\n", maxNum);

    return 0;
}
