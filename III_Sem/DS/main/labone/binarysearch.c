#include <stdio.h>

int main(){
    int n, n1, i, j, flag = 0, pos;
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
    printf("\nEnter number you want to search : ");
    scanf("%d", &n1);
    int high = n-1, low = 0;
    while(low <= high){
        pos = (high+low)/2;
        if(a[pos] == n1) { flag = 1; break;}
        if(a[pos] > n1){
            high = pos -1;
        }
        else {
            low = pos+1;
        }
    }

    if(flag){
        printf("Number found at positions : %d", pos + 1);
    } else {
        printf("Number not present in list");
    }
}

