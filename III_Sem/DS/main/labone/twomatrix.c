#include <stdio.h>

int main(){
    int n, n1, i, j;
    printf("Enter number of elements : ");
    scanf("%d %d", &n, &n1);
    int a[n][n1], b[n][n1], added[n][n1];
    printf("Enter the elements for first matrix : ");
    for(i = 0; i < n; i++){
        for(j = 0; j < n1; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements for second matrix : ");
    for(i = 0; i < n; i++){
        for(j = 0; j < n1; j++){
            scanf("%d", &b[i][j]);
        }
    }

    for(i = 0; i < n; i++){
        for(j = 0; j < n1; j++){
            added[i][j] = a[i][j] + b[i][j];
        }
    }
    printf("Matrix C is : \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n1; j++){
            printf("%d ", added[i][j]);
        }
        printf("\n");
    }
}
