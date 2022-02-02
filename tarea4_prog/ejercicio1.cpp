/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Realizar un programa que a través de un menú permita realizar
  las operaciones de sumar, restar, multiplicar, dividir y salir.
  Las operaciones constarán solamente de dos operandos.
  
  El menú será visualizado por una función sin argumentos,
  que devolverá como resultado la opción elegida. La ejecución será de 
  la forma siguiente:
    - Sumar
    - Restar
    - Multiplicar
    - Dividir
    - Salir 
*/

#include <iostream>

int main() {
  std::uint16_t opcion;
  double numero1, numero2;
  bool valido;

  // El programa realiza desde una hasta infinidad de ejecuciones
  // hasta que se ingrese la opción `5`
  do {
  
    std::cout << "Menú de opciones:\n"
      << "    1. Sumar\n"
      << "    2. Restar\n"
      << "    3. Multiplicar\n"
      << "    4. Dividir\n"
      << "    5. Salir\n";    
    
    // Preguntar por una opción las veces que sea necesario
    // hasta que se ingrese una opción valida aprovechando  el do-while
    do {  
      std::cout << "Ingresa la opción que deseas: ";
      std::cin >>  opcion;
      
      valido = opcion <= 5 && opcion >= 1;
      if (!valido) std::cout << "Error: Ingresa una opción valida.\n";
    } while (!valido);
    
    if (opcion == 5) continue;
    
    std::cout << "Ingresa el primer número: ";
    std::cin >> numero1;
                  
    std::cout << "Ingresa el segundo número: ";
    std::cin >> numero2;
      
    std::cout << "El resultado es: ";
      
    switch (opcion) {
      case 1: std::cout << numero1 + numero2; break;
      case 2: std::cout << numero1 - numero2; break;
      case 3: std::cout << numero1 * numero2; break;
      case 4: std::cout << numero1 / numero2; break;
      default: continue;
    }
    
    std::cout << "\n";
  } while (opcion != 5);

  return 0;
}
