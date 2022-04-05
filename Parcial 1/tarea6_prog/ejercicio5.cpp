/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que simule el funcionamiento de una máquina de venta de refrescos.
  Se debe contar con una matriz que almacena el nombre del producto, la cantidad disponible y el precio.
  El usuario puede seleccionar una bebida y se debe validar la existencia y realizar la venta.

*/

#include <iostream>

int main() {

  const int CN = 10;


  std::uint16_t opcion;
  double precio_cantidad[10][2] = {
      {16.0, 4},
      {14.0, 0},
      {16.0, 3},
      {15.0, 4},
      {17.0, 5},
      {15.0, 2},
      {19.0, 1},
      {15.5, 3},
      {14.5, 0},
      {12.0, 9},
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

  std::cout << "   Producto\tCant\tPrecio\n";

  for (int i=0; i < CN; i++) {
    std::cout
        << i+1 << ((i+1<10) ? "  " : " ")
        << nombres[i] << "\t"
        << precio_cantidad[i][1] << "\t"
        << precio_cantidad[i][0] << "\n"
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
  if (precio_cantidad[opcion][1] == 0) {
    std::cout << "Lo siento, no quedan más refrescos del numero ingresado\n";
    return 0;
  } else {
    std::cout << "Por un \"" << nombres[opcion] << "\" la cantidad a pagar es: $" << precio_cantidad[opcion][1] << "\n";
    std::cout << "Gracias por su compra\n";
  }
}