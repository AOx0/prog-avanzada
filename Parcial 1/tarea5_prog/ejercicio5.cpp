/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Hacer un programa en c++ que simule el funcionamiento de una máquina de venta de refrescos.
  Se debe contar con un vector que almacene el nombre, otro vector que almacene la cantidad disponible y
  otro vector con el precio. El usuario puede seleccionar una bebida y se debe validar la existencia y realizar la venta.
*/

#include <iostream>

int main() {

  const int CN = 10;

  srand(time(NULL));

  std::uint16_t opcion;
  std::uint64_t cantidad[CN] = {};
  double precio[CN] = {
      16.0,
      14.0,
      16.0,
      15.0,
      17.0,
      15.0,
      19.0,
      15.5,
      14.5,
      12.0,
  };
  std::string nombres[CN] = {
      "Coca-Cola",
      "Pepsi",
      "Fanta",
      "Sprite",
      "Fresca",
      "Del Valle",
      "Manzanita",
      "Senzao",
      "Delaware",
      "Agua pura",
  };

  // La cantidad se genera aleatoriamente
  for (int i=0; i < CN; i++) {
    if (i == 3) cantidad[i] = 0;
    else cantidad[i] = rand() % 6;
  }

  std::cout << "   Producto\tCant\tPrecio\n";

  for (int i=0; i < CN; i++) {
    std::cout
      << i+1 << ((i+1<10) ? "  " : " ")
      << nombres[i] << "\t"
      << cantidad[i] << "\t"
      << precio[i] << "\n"
    ;
  }

  bool valido = false;
  do {
    std::cout << "Ingresa el número de la bebida que deseas: ";
    std::cin >> opcion;

    if (opcion > 0 && opcion <= 10) valido = true;
    else {
      std::cout << "Ingresa un número de refresco válido\n";
    }
  } while (!valido);

  opcion--;
  if (cantidad[opcion] == 0) {
    std::cout << "Lo siento, no quedan más refrescos del numero ingresado\n";
    return 0;
  } else {
    std::cout << "Por un \"" << nombres[opcion] << "\" la cantidad a pagar es: $" << precio[opcion] << "\n";
    std::cout << "Gracias por su compra\n";
  }




}