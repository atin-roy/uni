#include <stdio.h>

void bubbleSort(int arr[], int n) {
  int temp;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
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

  bubbleSort(arr, n);

  printf("The sorted array is:\n");
  printArray(arr, n);

  return 0;
}
