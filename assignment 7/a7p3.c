#include <math.h>
#include <stdio.h>

#define EPSILON 0.000001

double f(double x) { return x * x * x - 9 * x + 1; }

void falsePosition(double a, double b) {
  if (f(a) * f(b) >= 0) {
    printf("The function has the same sign at points a and b.\n");
    return;
  }

  double c = a;
  int iteration = 0;

  while ((b - a) >= EPSILON) {
    c = (a * f(b) - b * f(a)) / (f(b) - f(a));

    printf("Iteration %d: c = %.6f\n", iteration, c);

    if (fabs(f(c)) < EPSILON) {
      break;
    }

    else if (f(c) * f(a) < 0) {
      b = c;
    } else {
      a = c;
    }

    iteration++;
  }

  printf("The root is: %.6f\n", c);
}

int main() {
  double a, b;

  printf("Enter the first guess (a): ");
  scanf("%lf", &a);
  printf("Enter the second guess (b): ");
  scanf("%lf", &b);

  falsePosition(a, b);

  return 0;
}
