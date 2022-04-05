/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que permita sumar la sucesión de los números:
  
      2^1+2^2+...+2^n
      
  siendo n un número que se ingresa por medio del teclado.
*/


#include <iostream>

// Para poder usar `pow(_, _)`
#include <cmath>

int main() {
  
  std::int64_t i, n, resultado=0;
  
  std::cout << "Ingresa el valor de n: ";
  std::cin >> n;
  
  for (i=1; i<=n; i++) {
    resultado +=  pow(2, i);
  }
  
  std::cout << "El resultado es " << resultado << std::endl;

  return 0;
}