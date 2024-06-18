#include <stdio.h>

int findLargest(int arr[], int n) {
  int largest = arr[0];
  for (int i = 1; i < n; i++) {
    if (arr[i] > largest) {
      largest = arr[i];
    }
  }
  return largest;
}

int main() {
  int n;

  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);

  int arr[n];

  printf("Enter the elements of the array:\n");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int largest = findLargest(arr, n);
  printf("The largest element in the array is: %d\n", largest);

  return 0;
}
