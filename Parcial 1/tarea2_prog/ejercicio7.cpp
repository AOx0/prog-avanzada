/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que escriba en pantalla los números
  múltiplos de 3 comprendidos del 1 al 100.
*/

#include <iostream>

int main() {
  std::uint16_t i = 1;
  
  while (i<= 100) {
    if (i % 3 == 0) std::cout << i << '\n';
    i++;
  }

	return 0;
}