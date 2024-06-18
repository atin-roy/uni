
#include <stdio.h>

int isPrime(int n) {
  if (n <= 1) {
    return 0;
  }
  for (int i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}

void checkSumOfTwoPrimes(int n) {
  int found = 0;
  for (int i = 2; i <= n / 2; i++) {
    if (isPrime(i) && isPrime(n - i)) {
      printf("%d can be expressed as the sum of %d and %d, which are both "
             "prime numbers.\n",
             n, i, n - i);
      found = 1;
    }
  }
  if (found == 0) {
    printf("%d cannot be expressed as the sum of two prime numbers.\n", n);
  }
}

int main() {
  int number;

  printf("Enter a number: ");
  scanf("%d", &number);

  checkSumOfTwoPrimes(number);

  return 0;
}
