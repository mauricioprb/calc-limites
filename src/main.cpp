#include <iostream>
#include <vector>
#include <string>
#include "../include/matplotlibcpp.h"

namespace plt = matplotlibcpp;

using namespace std;

double calcularLimite(double a, double b, double c, double x)
{
  return a * x * x + b * x + c;
}

int main()
{
  // Coeficientes do polinômio
  double a, b, c;

  // Solicita ao usuário os coeficientes
  cout << "Digite o coeficiente a: ";
  cin >> a;

  cout << "Digite o coeficiente b: ";
  cin >> b;

  cout << "Digite o coeficiente c: ";
  cin >> c;

  double x;

  // Solicita ao usuário o valor de x
  cout << "Digite o valor de x para calcular o limite: ";
  cin >> x;

  // Calcula o limite do polinômio
  double limite = calcularLimite(a, b, c, x);

  cout << "O limite do polinômio é: " << limite << endl;

  // Gera valores para plotagem
  vector<double> x_values;
  vector<double> y_values;

  for (double i = x - 2; i <= x + 2; i += 0.01)
  {
    x_values.push_back(i);
    y_values.push_back(calcularLimite(a, b, c, i));
  }

  // Adiciona pontos ao gráfico
  plt::plot({x}, {limite}, "o");

  plt::plot(x_values, y_values);
  plt::grid(true);

  string equacao = "y = " + to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c);
  plt::named_plot(equacao, x_values, y_values);

  plt::title("Gráfico da função");

  plt::legend();

  plt::show();

  return 1;
}