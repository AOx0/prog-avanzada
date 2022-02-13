/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en c++ que permita calcular y almacenar en un vector el salario de un grupo de trabajadores.
  Se entiende que existe un vector con los nombres, un vector con la cantidad de horas trabajadas y otro vector
  con el valor de la hora.
*/

#include <iostream>

int main() {

  double salarios_por_hora[5] = {}, horas[5] = {}, a_pagar[5] = {};

  // Salarios por hora
  for (int i=0; i < 5; i++) {
    std::cout << "Salario por hora trabajador " << i + 1 << ": ";
    std::cin >> salarios_por_hora[i];
  }

  std::cout << "\n";

  // Salarios por hora
  for (int i=0; i < 5; i++) {
    std::cout << "Horas del trabajador " << i + 1 << ": ";
    std::cin >> horas[i];
  }

  // Salarios por hora
  for (int i=0; i < 5; i++) {
    a_pagar[i] = horas[i] * salarios_por_hora[i];
  }

  std::cout << "\n";

  for (int i=0; i < 5; i++) {
    std::cout
      << "Salario del trabajador " << i << " : "
      << a_pagar[i] << "\n";
  }

}