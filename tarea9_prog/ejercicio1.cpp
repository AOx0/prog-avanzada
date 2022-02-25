/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer una función en C++ que calcule la media de tres números leídos por teclado.
 */

#include <iostream>

using namespace std;

double media();

int main() {
  media();
}

double media() {
  double suma=0, num;
  for (int i=0; i<3; i++) {
    cout << "Ingresa el número " << i << ": ";
    cin >> num;
    suma += num;
  }

  return suma/3.0;
}