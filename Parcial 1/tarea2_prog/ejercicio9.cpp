/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que calcule el factorial de un número.
*/

#include <iostream>

int main() {
  std::uint16_t num;
  std::uint64_t resultado = 1;
  
  std::cout << "Ingresa un número: ";
  std::cin >> num; 
  
  std::cout << "El factorial de " << num << " es: ";
  
  while (num != 0) {
    resultado *= num;
    num--;
  } 
  
  std::cout << resultado << std::endl;

	return 0;
}