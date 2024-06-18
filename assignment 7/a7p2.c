#include <math.h>
#include <stdio.h>


#define EPSILON 0.000001

double f(double x) { return x * x * x + 8 * x - 4; }

double f_prime(double x) { return 3 * x * x + 8; }

void newtonRaphson(double x0) {
  double x1;
  int iteration = 0;

  while (1) {
    x1 = x0 - f(x0) / f_prime(x0);

    printf("Iteration %d: x = %.6f\n", iteration, x1);

    if (fabs(x1 - x0) < EPSILON) {
      break;
    }

    x0 = x1;
    iteration++;
  }

  printf("The root is: %.6f\n", x1);
}

int main() {
  double initial_guess;

  printf("Enter initial guess: ");
  scanf("%lf", &initial_guess);

  newtonRaphson(initial_guess);

  return 0;
}
