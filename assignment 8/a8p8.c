#include <stdio.h>
double function(double x) { return 1 / (1 + x); }

double sumOfFunction(double a, double b, double h) {
  double sum = 0;
  int n = (int)((b - a) / h);
  for (int i = 1; i < n; i++) {
    sum += function(a + i * h);
  }
  return sum;
}

double trapezoidalRule(double a, double b, double h) {
  return (h / 2) * (function(a) + 2 * sumOfFunction(a, b, h) + function(b));
}

double simpsonsOneThirdRule(double a, double b, double h) {
  return (h / 3) * (function(a) + 4 * sumOfFunction(a, b, h) + function(b));
}

int main() {
  double a = 0.0;
  double b = 6.0;
  int n = 6;
  double h = (b - a) / n;

  double trapezoidalResult = trapezoidalRule(a, b, h);

  double simpsonsResult = simpsonsOneThirdRule(a, b, h);

  printf("Using Trapezoidal Rule:\n");
  printf("Approximate value of the integral: %.6f\n", trapezoidalResult);

  printf("\nUsing Simpson's 1/3 Rule:\n");
  printf("Approximate value of the integral: %.6f\n", simpsonsResult);

  return 0;
}
