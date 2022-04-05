/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa que genere un vector de 100 números aleatorios y realice el ordenamiento de los mismos.
*/

#include <iostream>

int main() {

  srand(time(NULL));

  std::int64_t arreglo[100] = {};
  std::int64_t temp;

  // Primer arreglo
  for (int i=0; i < 100; i++) {
    // Generaremos números positivos y negativos aleatorios de -5000 a 5000
    arreglo[i] = (rand() % 5000) * (rand() % 2 ? -1 : 1);
  }

  std::cout << "Arreglo generado: ";
  for (int i=0; i < 100; i++) {
    std::cout << arreglo[i] << " ";
  }
  std::cout << "\n\n";

  // Algoritmo de ordenación
  for (int i=0; i < 100; i++) {
    for (int j=0; j < 100; j++) {
      if (arreglo[i] > arreglo[j]) {
        temp = arreglo[i];
        arreglo[i] = arreglo[j];
        arreglo[j] = temp;
      }
    }
  }

  std::cout << "Arreglo ordenado: ";
  for (int i=0; i < 100; i++) {
    std::cout << arreglo[i] << " ";
  }
  std::cout << "\n";
}