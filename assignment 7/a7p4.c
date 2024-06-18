#include <math.h>
#include <stdio.h>


#define SIZE 3
#define EPSILON 1e-9

void printMatrix(double mat[SIZE][SIZE + 1]) {
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j <= SIZE; j++) {
      printf("%10.4f ", mat[i][j]);
    }
    printf("\n");
  }
}

void swapRows(double mat[SIZE][SIZE + 1], int row1, int row2) {
  for (int i = 0; i <= SIZE; i++) {
    double temp = mat[row1][i];
    mat[row1][i] = mat[row2][i];
    mat[row2][i] = temp;
  }
}

void gaussElimination(double mat[SIZE][SIZE + 1]) {
  for (int i = 0; i < SIZE; i++) {
    int maxRow = i;
    for (int k = i + 1; k < SIZE; k++) {
      if (fabs(mat[k][i]) > fabs(mat[maxRow][i])) {
        maxRow = k;
      }
    }
    swapRows(mat, i, maxRow);

    for (int k = i + 1; k < SIZE; k++) {
      double factor = mat[k][i] / mat[i][i];
      for (int j = i; j <= SIZE; j++) {
        mat[k][j] -= factor * mat[i][j];
      }
    }
  }

  double solution[SIZE];
  for (int i = SIZE - 1; i >= 0; i--) {
    solution[i] = mat[i][SIZE] / mat[i][i];
    for (int k = i - 1; k >= 0; k--) {
      mat[k][SIZE] -= mat[k][i] * solution[i];
    }
  }

  printf("Solution using Gauss Elimination with Pivoting:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("x%d = %.6f\n", i + 1, solution[i]);
  }
}

void gaussJordan(double mat[SIZE][SIZE + 1]) {
  for (int i = 0; i < SIZE; i++) {
    int maxRow = i;
    for (int k = i + 1; k < SIZE; k++) {
      if (fabs(mat[k][i]) > fabs(mat[maxRow][i])) {
        maxRow = k;
      }
    }
    swapRows(mat, i, maxRow);

    double diagElement = mat[i][i];
    for (int j = 0; j <= SIZE; j++) {
      mat[i][j] /= diagElement;
    }

    for (int k = 0; k < SIZE; k++) {
      if (k != i) {
        double factor = mat[k][i];
        for (int j = 0; j <= SIZE; j++) {
          mat[k][j] -= factor * mat[i][j];
        }
      }
    }
  }

  printf("Solution using Gauss-Jordan Method:\n");
  for (int i = 0; i < SIZE; i++) {
    printf("x%d = %.6f\n", i + 1, mat[i][SIZE]);
  }
}

void menu() {
  printf("Choose a method to solve the system of equations:\n");
  printf("1. Gauss Elimination with Pivoting\n");
  printf("2. Gauss-Jordan Method\n");
  printf("3. Exit\n");
}

int main() {
  double mat[SIZE][SIZE + 1] = {{1, 1, 1, 3}, {2, 3, 1, 6}, {1, -1, -1, -3}};

  while (1) {
    menu();
    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      double matCopy[SIZE][SIZE + 1];
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
          matCopy[i][j] = mat[i][j];
        }
      }
      gaussElimination(matCopy);
      break;
    }
    case 2: {
      double matCopy[SIZE][SIZE + 1];
      for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
          matCopy[i][j] = mat[i][j];
        }
      }
      gaussJordan(matCopy);
      break;
    }
    case 3:
      return 0;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  }

  return 0;
}
