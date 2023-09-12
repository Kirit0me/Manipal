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
        for(j = i; j<n; j++){
            if(a[i]> a[j]){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

