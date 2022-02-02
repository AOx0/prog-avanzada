/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que calcule las notas de un alumno,
  el programa va a terminar cuando el estudiante no quiera ingresar más notas.
*/

#include<cstdio>
#include <iostream>

int main() {
	double promedio, nota;
  std::uint16_t i = 0;
  
  while (1) {
    std::cout << "Ingresa la calificación " << i << "(o escribe '-1' para salir): ";
    std::cin >> nota;
    
    if (nota == -1) break;
    promedio += nota;
    
    i++;
  }
  
  if (i != 0) {
    std::cout << "El promedio que tienes es: ";
    printf("%.2f\n", promedio/i);
  }
  
  return 0;
}