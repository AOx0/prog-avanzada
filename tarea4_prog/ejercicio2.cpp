/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Utilizando la estructura Switch, realice un programa en el cual me muestre un menú
  de la carta del restaurante, el usuario puede realizar solicitud de diferentes platos y
  bebidas y al final obtener la cuenta a pagar.
*/


#include <iostream>

int main() {
  
  short unsigned int opcion;
  double total = 0;
  
  std::cout 
    << "Menú: \n"
    << "1. Pizza\t$95.0\n"
    << "2. Ensalada\t$40.0\n"
    << "3. Helado\t$99.99\n"
    << "4. Es todo\n"
  ;
  
  do {    
    std::cout << "Ingresa qué opción deseas: ";
    std::cin >> opcion;
    
    if (opcion > 4 || opcion == 0) std::cout << "Error: Ingresa una opción válida\n";
    
    switch (opcion) {
      case 1:
        total += 95;
        break;
      case 2:
        total += 40;
        break;
      case 3:
        total += 99.99;
        break;
    }
    
  } while (opcion != 4);
  
  std::cout << "El total a pagar es " << total << std::endl;

  return 0;  
}