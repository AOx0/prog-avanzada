/*
  Daniel Alejandro Osornio López -- Programación Avanzada
  
  Utilizando la estructura DO – WHILE, realice un programa en el cual me muestre
  un menú de la carta del restaurante, el usuario puede realizar solicitud de diferentes
  platos y bebidas y al final obtener la cuenta a pagar. 
*/

#include <cstdio>
#include <iostream>

struct Producto {

  public: 
  std::string nombre;
  double precio;
  
  Producto(std::string nombre, double precio) :
    nombre(nombre),
    precio(precio)
  {};
  
  static void mostrarLista(Producto * listaProductos, int lenLista) {
    for (int i=0; i < lenLista; i++) {
      printf("    %d. %-15s %5.2lf\n", i, listaProductos[i].nombre.c_str(), listaProductos[i].precio);
    }
  }
};



int main() {

  const int LEN_LISTA = 5;
  double total;
  std::int16_t orden;
  bool ordenValida;
  
  std::cout << "Menú: \n";
  
  Producto productos[] = {
    Producto("Pizza", 23.4),
    Producto("Ensalada", 15.0),
    Producto("Coca-Cola", 25),
    Producto("Agua simple", 2.5),
    Producto("Sprite", 23)
  };
  
  Producto::mostrarLista(productos, LEN_LISTA);
  
  std::cout << "Nota: Ingrese el número marcado para el producto en el menú para ordenarlo\n";
  std::cout << "Nota: Ingrese cualquier número negativo para dejar de capturar órdenes.\n";
  
  do {
    
    do {
      
      std::cout << "Ingresa el número del producto: ";
      std::cin >> orden;
      
      ordenValida = orden < LEN_LISTA; 
      if (!ordenValida) std::cout << "Error: Ingresa un producto válido\n";
    } while (!ordenValida);
    
    total += productos[orden].precio;
    
  } while (orden > 0);
  
  std::cout << "El total a pagar es: ";
  printf("$%.2lf\n", total);

  return 0;
}