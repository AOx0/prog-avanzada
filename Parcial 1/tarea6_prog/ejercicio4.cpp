/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que permita calcular y almacenar en una matriz los salarios de un grupo de trabajadores.
  Se debe almacenar los nombres, la cantidad de horas trabajadas, el valor de la hora y el valor total a pagar.
*/

#include <iostream>

int main() {

  std::string nombres[5];
  // 5 trabajadores, cada uno con horas trabajadas y valor de la hora
  double matriz[5][3], suma = 0, pagar;


  for (int i=0; i<5; i++) {
    std::cout << "Ingrese el nombre del trabajador: ";
    std::getline(std::cin, nombres[i], '\n');

    std::cin.clear();
    std::cin.sync();

    std::cout << "Salario por hora de " << nombres[i] << ": ";
    std::cin >> matriz[i][0];

    std::cin.ignore();

    std::cout << "Número de horas trabajadas de " << nombres[i] << ": ";
    std::cin >> matriz[i][1];

    std::cin.ignore();

    std::cout << "\n";
  }

  for (int i=0; i<5; i++) {
    std::cout << "Trabajador " << i << ": " << nombres[i] << "\n";

    std::cout << "Salario: " << matriz[i][0] << std::endl;

    std::cout << "Horas trabajadas:  " << matriz[i][1] << std::endl;

    pagar = matriz[i][0] * matriz[i][1];
    std::cout << "A pagar: " << pagar << std::endl;

    suma += pagar;

    std::cout << "\n";
  }

  std::cout << "\nTotal de la nómina: " << suma << std::endl;

}