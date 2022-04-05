/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ para ayudar a un trabajador a saber cuál será
  su sueldo semanal, se sabe que, si trabaja 40 horas o menos, se le pagará
  $20 por hora, pero si trabaja más de 40 horas entonces las horas extras se
  le pagarán a $25 por hora.
*/

#include <iostream>

int main() {
  std::uint32_t horasTrabajadas, salario;
  
  std::cout << "Ingresa el número de horas trabajadas: ";
  std::cin >> horasTrabajadas;
  
  salario = horasTrabajadas * 20;
  salario += horasTrabajadas > 40 ? (horasTrabajadas - 40) * 5 : 0;

  std::cout << "Salario total: " << salario << std::endl;

	return 0;
}
