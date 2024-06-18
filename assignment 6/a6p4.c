#include <stdio.h>

void decimalToBinary(int n) {
  if (n > 1) {
    decimalToBinary(n / 2);
  }
  printf("%d", n % 2);
}

int main() {
  int number;

  printf("Enter a decimal number: ");
  scanf("%d", &number);

  if (number < 0) {
    printf("Negative numbers is not supported\n");
  } else {
    printf("Binary representation of %d is: ", number);
    decimalToBinary(number);
    printf("\n");
  }

  return 0;
}
