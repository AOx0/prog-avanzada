/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que escriba los números pares del 1 al 1000.
*/

#include <iostream>

int main() {
  for (int i=2; i<=1000; i+=2) std::cout << i << "\n";
  return 0;
}