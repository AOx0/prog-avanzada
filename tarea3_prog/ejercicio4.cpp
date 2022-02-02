/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que calcule el factorial de un número.
*/

#include <iostream>

int main() {
  std::uint64_t factorial = 1;
  std::int32_t num;
  
  std::cout << "Ingresa el número del que deseas calcular su factorial: ";
  std::cin >> num;
  
  for (std::int32_t i=1; i<=num; i++) {
    factorial *= i;
  };
  
  std::cout << "El factorial de " << num << " es " << factorial << std::endl;

  return 0;
}