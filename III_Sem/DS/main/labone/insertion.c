#include <stdio.h>

void insert(int a[], int n)
{
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = a[i];
        j = i - 1;

        while(j>=0 && temp <= a[j])
        {
            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = temp;
    }
}

void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}


int main()
{
    int c;
    scanf("%d", &c);
    int a[c];
    int i;
    for (i = 0; i < c; i++) {
            scanf("%d", &a[i]);
    }
    printf("Before sorting array elements are - \n");
    printArr(a, c);
    insert(a, c);
    printf("\nAfter sorting array elements are - \n");
    printArr(a, c);

    return 0;
}
