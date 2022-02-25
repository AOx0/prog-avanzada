/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer una función en C++ que calcule un número elevado a otro.
 */

#include <iostream>

using namespace std;

uint64_t potencia(uint16_t base, uint16_t exponente);

int main() {
  uint16_t num;

  cout << "Ingresa un número: ";
  cin >> num;

  cout << "Su 2 potencia es: " << potencia(num, 2) << endl;
}

uint64_t potencia(uint16_t base, uint16_t exponente) {
  std::uint64_t resultado = 1;

  for (int i=0; i<exponente; i++) {
    resultado *= base;
  }

  return resultado;
}