#include <stdio.h>

int main() {
    int n, m;

    printf("enter the size of matrix :");
    scanf("%d %d", &n, &m);

    int matrix[n][m];
    int transpose[m][n];
    int i, j;

    printf("Enter elements of the %dx%d matrix:\n", n, m);

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("Transposed matrix of given matrix is:\n");

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }

    return 0;
}