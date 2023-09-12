#include <stdio.h>

int main(){
    int n, i, j, pos;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements : ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++){
        for(j = 0; j<n-i-1; j++){
            if(a[j]> a[j+1]){
                int t = a[j+1];
                a[j+1] = a[j];
                a[j] = t;
            }
        }
    }

    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}
