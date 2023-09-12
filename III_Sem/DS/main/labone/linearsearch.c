#include <stdio.h>

int main(){
    static int posval = 0;
    int n, n1, i, j = 0, pos[10];
    printf("Enter number of elements : ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements : ");
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    printf("Enter number you want to search : ");
    scanf("%d", &n1);
    for(i = 0; i < n; i++){
        if(n1 == a[i]){
            j = 1;
            pos[posval] = i+1;
            posval += 1;
        }
    }

    if(j){
        printf("Number found at positions : \n");
        for(i = 0; i < posval; i++){
            printf("%d, ", pos[i]);
        }
    } else {
        printf("Number not present in list");
    }
}
