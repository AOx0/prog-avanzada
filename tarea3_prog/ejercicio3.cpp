/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que calcule la suma de los números pares e impares.
  (Supondré que es del 1 al 1000 como el problema 2)
*/

#include <iostream>

int main() {
  std::int32_t pares = 0;
  
  // Usando un for-loop para "contar" el número de pares
  for (int i=2; i<=1000; i+=2) {
    pares++;
  }
  
  std::cout << "Del 1 al 1000 hay...\n";
  std::cout << "Pares:   " << pares << '\n';
  std::cout << "Impares: " << 1000-pares << '\n';
  
  return 0;
}
