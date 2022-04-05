/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que permita calcular el salario de un grupo de trabajadores usando estructuras dinámicas.
*/

#include <iostream>

struct Info {
  double salario_por_hora;
  double horas;

  double aPagar() const {
    return salario_por_hora * horas;
  }
};



int main() {
  int cantidad;
  std::cout << "Ingresa el número de empleados: ";
  std::cin >> cantidad;

  Info * trabajadores = new Info[cantidad];

  // Salarios por hora
  for (int i=0; i < cantidad; i++) {
    double salario = rand() % 300 + 105;
    trabajadores[i].salario_por_hora = salario;
  }

  std::cout << "\n";

  // Salarios por hora
  for (int i=0; i < cantidad; i++) {
    double salario = rand() % 20 + 20;
    trabajadores[i].horas = salario;
  }

  for (int i=0; i < cantidad; i++) {
    std::cout
        << "A pagar al trabajador " << i + 1 << " : "
        << trabajadores[i].aPagar() << "\n";
  }

  delete [] trabajadores;
}
