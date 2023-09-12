#include <stdio.h>
static int n = 0;
int main(){
    int a, b, i;
    printf("Number to multiply : ");
    scanf("%d %d", &a, &b);
    int result = multiply(a, b);
    printf("Result is : %d", result);
    printf("\n Number of array elements : ");
    int num, size_arr;
    scanf("%d", &size_arr);
    int arr[size_arr];
    for(i = 0; i < size_arr; i++){
        scanf("%d", &arr[i]);
    }
    printf("Number to find : ");
    scanf("%d", &num);
    int c = binarysearch(arr, num, 0, size_arr);
    printf("\nAt %d\n", c+1);
	SelectionSort(arr, size_arr, 0);
    for(i = 0; i < size_arr; i++){
        printf("%d\t", arr[i]);
    }
}

int multiply(int a, int b){
    if(b > 0){
        n+=a;
        b -=1;
        multiply(a, b);
    }
    else{
        return n;
    }
}

int binarysearch(int a[], int n1, int low, int high){
    int mid = low + (high-low)/2;
    if(high < low){
        printf("Number not found\n");
        return -1;
    }
    else if(a[mid] == n1){
        return mid;
    }
    else if(a[mid] < n1){
        return binarysearch(a, n1, mid+1, high);
    }
    else if(a[mid] > n1){
        return binarysearch(a, n1, low, mid-1);
    }
}
void SelectionSort(int arr[], int size, int index) {
    if (index >= size - 1) {
        return; 
    }

    int minIndex = index;
    for (int i = index + 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i; 
        }
    }

    if (minIndex != index) {
		int temp = arr[minIndex];
		arr[minIndex] = arr[index];
		arr[index] = temp;
    }
    SelectionSort(arr, size, index + 1); 

}
