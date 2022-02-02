/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que escriba los números del 1 al 100.
*/

#include <iostream>

int main() {
  std::uint16_t i = 1;
  
  while (i<= 100) {
    std::cout << i << '\n';
    i++;
  }

	return 0;
}