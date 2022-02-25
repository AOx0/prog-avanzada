/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer una función en C++ que calcule el factorial de un número.
 */

#include <iostream>

using namespace std;

uint64_t factorial(uint16_t num);

int main() {
  uint16_t num;

  cout << "Ingresa un número: ";
  cin >> num;

  cout << "Su factorial es: " << factorial(num) << endl;
}

uint64_t factorial(uint16_t num) {
  std::uint64_t resultado = 1;

  while (num != 0) {
    resultado *= num;
    num--;
  }

  return resultado;
}