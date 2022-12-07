#include <math.h>
#include <stdio.h>

double newtonMethod(double y) {
  // x_old = chute inicial.
  double x_old = 1.0, tol = 1.0e-04;
  double error = 1.0, x, f, fp;

  printf("\nPara a equação com g = %.1lf:\n", y);
  while (error > tol) {
    // f(x_old) = g(T).
    // Para g(T) = 0.1, f = 0.9 - ...
    // Para g(T) = 0.9, f = 0.1 - ...
    f = (1 - y) - (1 + x_old + (pow(x_old, 2) / 2.0)) * exp(-x_old);

    // fp = Derivada de f.
    fp = 0.5 * exp(-x_old) * pow(x_old, 2);

    // Fórmula para o Método de Newton
    x = x_old - (f / fp);

    error = fabs(x - x_old) / fabs(x);

    printf("x = %lf; erro = %lf\n", x, error);

    x_old = x;
  }

  return x;
}

int main() {
  double g_01 = 0.1, g_09 = 0.9;
  double T_01, T_09;

  T_01 = newtonMethod(g_01);
  T_09 = newtonMethod(g_09);

  printf("\nPara a equação com g = %.1lf, T 0.1 = %lf\n", g_01, T_01);

  printf("Para a equação com g = %.1lf, T 0.9 = %lf\n", g_09, T_09);

	printf("Tempo de subida: %lf\n", T_09 - T_01);
  return 0;
}