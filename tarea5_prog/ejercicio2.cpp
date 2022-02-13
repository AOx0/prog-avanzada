/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en c++ que solicite al usuario 20 números los cuales serán almacenados 10
  en un vector A y 10 en un vector B. Al final se debe generar un vector C que en donde se almacene
  la suma de los números de los vectores A y B.
*/

#include <iostream>

int main() {
  
  std::int64_t arreglo1[10] = {}, arreglo2[10] = {}, arreglo3[10] = {};

  // Primer arreglo
  for (int i=0; i < 10; i++) {
    std::cout << "Num " << i + 1 << ": ";
    std::cin >> arreglo1[i];
  }

  // Segundo arreglo
  for (int i=0; i < 10; i++) {
    std::cout << "Num " << i + 1 << ": ";
    std::cin >> arreglo2[i];
  }

  // Arreglo de sumas
  for (int i=0; i < 10; i++) {
    arreglo3[i] = arreglo1[i] + arreglo2[i];
  }

  std::cout << "Arreglo C: ";
  for (int i=0; i < 10; i++) {
    std::cout << arreglo3[i] << " ";
  }
  std::cout << "\n";
}