#include <math.h>
#include <stdio.h>

#define EPSILON 0.0001

double f(double x) { return x * x * x + x * x - 1; }

void bisection(double a, double b) {
  if (f(a) * f(b) >= 0) {
    printf("You have not assumed right a and b.\n");
    return;
  }

  double c = a;
  while ((b - a) >= EPSILON) {
    c = (a + b) / 2;

    if (f(c) == 0.0)
      break;

    else if (f(c) * f(a) < 0)
      b = c;
    else
      a = c;
  }
  printf("The root of the polynomial x^3 + x^2 - 1 is: %.4f\n", c);
}

int main() {
  double a = 0, b = 1;
  bisection(a, b);
  return 0;
}
