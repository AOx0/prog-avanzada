/*
  Daniel Alejandro Osornio López
  
  Hacer un programa en C++ que permita realizar conversiones de longitud, temperatura, masa y tiempo
*/

#include <iostream>

int main() {
  std::uint16_t opcion;
  
  std::cout
    << "Menu de opciones:\n"
    << "1. Convertir metros a km\n"
    << "2. Convertir grados centígrados a fahrenheit\n"
    << "3. Convertir grados fahrenheit a centígrados\n"
    << "4. Convertir dias a segundos\n"
    << "5. Convertir kg a libras\n"
    << "6. Salir\n"
  ;
  
 do {    
    std::cout << "Ingresa qué opción deseas: ";
    std::cin >> opcion;
    
    if (opcion > 6 || opcion == 0) std::cout << "Error: Ingresa una opción válida\n";
    
    switch (opcion) {
      case 1:
        {
          double m;
          std::cout << "Ingresa la cantidad de metros: ";
          std::cin >> m;
          std::cout << m << " metros son " << m/1000 << " km.\n";
        }
        break;
      case 2:
        {
          double g;
          std::cout << "Ingresa la cantidad de grados centírados: ";
          std::cin >> g;
          std::cout << g << " grados centígrados son " << (g * 9.0/5.0)+32.0 << " grados fahrenheit.\n";
        }
        break;
      case 3:
        {
          double f;
          std::cout << "Ingresa la cantidad de fahrenheit: ";
          std::cin >> f;
          std::cout << f << " grados fahrenheit son " << (f-32.0)/(9.0/5.0) << " grados centígrados.\n";
        }
        break;
      case 4:
        {
          double d;
          std::cout << "Ingresa la cantidad de días: ";
          std::cin >> d;
          std::cout << d << " días son " << d*24*60*60 << " segundos.\n";
        }
        break;
      case 5:
        {
          double k;
          std::cout << "Ingresa la cantidad de kilogramos: ";
          std::cin >> k;
          std::cout << k << " kg son " << k * 2.20462 << " libra.\n";
        }
        break;
    }
    
  } while (opcion != 6);

  return 0;   
}