#include <stdio.h>

int main(){
  int arr[100], n;

  printf("\nPlease enter the number of elements: ");
  scanf("%d",&n);

  printf("\nEnter individual elements: ");
  for(int i=0; i<=n; i++){
    printf("\nEnter the (%d) element: ", i);
    scanf("%d", &arr[i]);
  };

  // Main sorting code
  // Coming in the next commit...
}
