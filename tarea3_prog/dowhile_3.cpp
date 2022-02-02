/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que calcule el factorial de un número usando el bucle do-while.
*/

#include <iostream>

int main() {
  std::uint64_t factorial = 1;
  std::int32_t num;
  
  std::cout << "Ingresa el número del que deseas calcular su factorial: ";
  std::cin >> num;
  
  std::cout << "El factorial de " << num << " es ";
  
  while (num>0) {
    factorial *= num;
    num--;
  };
  
  std::cout << factorial << std::endl;

  return 0;
}