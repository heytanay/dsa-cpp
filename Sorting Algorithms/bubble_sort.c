#include <stdio.h>

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    // Caller function
    int array[100], n;

    printf("Please enter the number of array elements: ");
    scanf("%d",&n);

    printf("Enter the array elements: \n");
    for (int i=0; i<=n; i++){
        printf("Enter the %d element: ",i);
        scanf("%d", &array[i]);
    };

    printf("Sorting the array...\n\n");

    for (int i=0; i<=n-1; i++){
        for (int j=0; j<=n-i-1; j++){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }

    printf("Printing the sorted array: \n[");
    for (int i=0; i<=n; i++){
        printf("%d, ",array[i]);
    }
    printf("]\n\n");
}