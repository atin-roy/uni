#include <math.h>
#include <stdio.h>

#define SIZE 3

double determinant(double mat[SIZE][SIZE], int n) {
  double det = 0;
  if (n == 1) {
    return mat[0][0];
  }

  double temp[SIZE][SIZE];
  int sign = 1;

  for (int f = 0; f < n; f++) {
    int subi = 0;
    for (int i = 1; i < n; i++) {
      int subj = 0;
      for (int j = 0; j < n; j++) {
        if (j == f)
          continue;
        temp[subi][subj] = mat[i][j];
        subj++;
      }
      subi++;
    }
    det += sign * mat[0][f] * determinant(temp, n - 1);
    sign = -sign;
  }

  return det;
}

void cofactor(double mat[SIZE][SIZE], double temp[SIZE][SIZE], int p, int q,
              int n) {
  int i = 0, j = 0;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (row != p && col != q) {
        temp[i][j++] = mat[row][col];
        if (j == n - 1) {
          j = 0;
          i++;
        }
      }
    }
  }
}

void adjoint(double mat[SIZE][SIZE], double adj[SIZE][SIZE]) {
  if (SIZE == 1) {
    adj[0][0] = 1;
    return;
  }

  int sign = 1;
  double temp[SIZE][SIZE];

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      cofactor(mat, temp, i, j, SIZE);
      sign = ((i + j) % 2 == 0) ? 1 : -1;
      adj[j][i] = sign * determinant(temp, SIZE - 1);
    }
  }
}

int inverse(double mat[SIZE][SIZE], double inv[SIZE][SIZE]) {
  double det = determinant(mat, SIZE);
  if (fabs(det) < 1e-9) {
    printf("Singular matrix, can't find its inverse\n");
    return 0;
  }

  double adj[SIZE][SIZE];
  adjoint(mat, adj);

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      inv[i][j] = adj[i][j] / det;
    }
  }

  return 1;
}

void multiply(double mat[SIZE][SIZE], double vec[SIZE], double result[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    result[i] = 0;
    for (int j = 0; j < SIZE; j++) {
      result[i] += mat[i][j] * vec[j];
    }
  }
}

// Function to print a vector
void printVector(double vec[SIZE]) {
  for (int i = 0; i < SIZE; i++) {
    printf("x%d = %.6f\n", i + 1, vec[i]);
  }
}

int main() {
  double mat[SIZE][SIZE] = {{1, 1, 1}, {1, 1, -1}, {1, -1, 1}};
  double constants[SIZE] = {6, 0, 2};

  double inv[SIZE][SIZE];
  if (inverse(mat, inv)) {
    double result[SIZE];
    multiply(inv, constants, result);
    printf("The solution is:\n");
    printVector(result);
  }

  return 0;
}
