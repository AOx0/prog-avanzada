/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que calcule la serie de Fibonacci.
  (Supondré que hay que calcular el número *n* de la serie)
*/

#include <iostream>

int main() {

  std::uint64_t resultado = 0, anterior = 1, temp;
  std::uint16_t n, i;
  
  std::cout << "Ingresa el número de fibonacci que deseas calcular: ";
  std::cin >> n;
  
  for (i=0;i<n; i++) {
    temp = resultado;
    resultado += anterior;
    anterior = temp;
    
    std::cout << resultado << ( n-1==i ? "\n" : ", ");
  }


  return 0;
}
