/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en c++ que solicite al usuario 10 números enteros,
  los almacene en un array e imprima el mayor, el menor, la suma y el promedio.
*/

#include <iostream>

int main() {
  
  std::int64_t arreglo[10] = {};
  std::int64_t grande = INT64_MIN, peque = INT64_MAX, suma = 0;
  
  for (int i=0; i < 10; i++) {
    std::cout << "Num " << i + 1 << ": ";
    std::cin >> arreglo[i]; 
  }

  for (int i=0; i < 10; i++) {
    if (arreglo[i] < peque) peque = arreglo[i];
    if (arreglo[i] > grande) grande = arreglo[i];
    suma += arreglo[i];
  }

  std::cout << "Arreglo: ";
  for (int i=0; i < 10; i++) {
    std::cout << arreglo[i] << " ";
  }
  std::cout << "\n";

  std::cout
    << "Suma:\t" << suma << "\n"
    << "Promedio: " << suma/10 << "\n"
    << "Mayor:\t" << grande << "\n"
    << "Menor:\t" << peque<< "\n"
  ;
}