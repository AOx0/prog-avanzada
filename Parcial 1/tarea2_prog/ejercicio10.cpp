/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ que lea n números y determine cuál
  es el mayor, el menor y la media de los números leídos.
*/

#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  float promedio;
  std::int64_t num, i, j, menor = INT64_MAX, mayor = INT64_MIN;
  
  std::cout << "¿Cuantos números deseas ingresar?: ";
  std::cin >> i;
  
  if (i <= 0) return 0;
  
  j = i;
  
  while (i != 0) {
    std::cout << "Ingresa un número: ";
    std::cin >> num;
    
    if (num < menor) menor = num;
    if (num > mayor) mayor = num;
    
    promedio += num;  
    i--;
  }
  
  std::cout << "El menor número ingresado fue: " << menor << '\n';
  std::cout << "El mayor número ingresado fue: " << mayor << '\n';
  std::cout << "El promedio fue de: ";
  
  printf("%0.5f\n", promedio/j);

	return 0;
}