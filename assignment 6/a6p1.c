#include <math.h>
#include <stdio.h>

int isArmstrong(int num) {
  int numCopy = num, rem, res = 0, digits = 0;

  while (numCopy != 0) {
    numCopy /= 10;
    digits++;
  }

  numCopy = num;

  while (numCopy != 0) {
    rem = numCopy % 10;
    res += pow(rem, digits);
    numCopy /= 10;
  }

  return (res == num);
}

int isPerfect(int num) {
  int sum = 0;

  for (int i = 1; i <= num / 2; i++) {
    if (num % i == 0) {
      sum += i;
    }
  }

  return (sum == num);
}

int main() {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  if (isArmstrong(number)) {
    printf("%d is an Armstrong number.\n", number);
  } else {
    printf("%d is not an Armstrong number.\n", number);
  }

  if (isPerfect(number)) {
    printf("%d is a Perfect number.\n", number);
  } else {
    printf("%d is not a Perfect number.\n", number);
  }

  return 0;
}
