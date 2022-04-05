/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en C++ para una tienda de zapatos que tiene una promoción de descuento para vender al mayor,
  esta dependerá del número de zapatos que se compren. Si son más de diez, se les dará un 10% de descuento sobre
  el total de la compra; si el número de zapatos es mayor de veinte, pero menor de treinta, se le otorga un 20%
  de descuento; y si son más treinta zapatos se otorgará un 40% de descuento. El precio de cada zapato es de $80.
*/

#include <iostream>

int main() {
  std::uint32_t numZapatos, total = 80; 
  std::cout << "Ingresa el número de zapatos a comprar: ";
  std::cin >> numZapatos;
  total *= numZapatos;
  
  if (numZapatos > 30) {
    total *= 0.6;
  } else if (numZapatos > 20) {
    total *= 0.8;
  } else if (numZapatos > 10) {
    total *= 0.9;
  } 

  std::cout << "El total a pagar por " << numZapatos << " zapatos es " << total << std::endl;

	return 0;
}