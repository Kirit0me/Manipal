#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, n3;
    printf("Enter the three values : ");
    scanf("%d %d %d", &n1, &n2, &n3);
    float avg = (n1+n2+n3)/3;
    printf("Average of %d %d %d is %f", n1, n2, n3, avg);
    return 0;
}
