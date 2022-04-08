#include <iostream>

using namespace std;

struct Persona {
  string nombre;
  string apellido;
};

struct Cliente {
  Persona info;
  string desea_comprar;
  double dinero;
  int cantidad;
};

struct Proveedor {
  Persona info;
  string desea_vender;
  int cantidad;
  double precio;
};

struct Venta {
  int id;
  Cliente cliente;
  Proveedor proveedor;
};

int main() {
  Venta venta = {
    123123, // ID
    { // Cliente
      { "Daniel", "Osornio" }, // Persona
      "Lámparas",              // Desea comprar
      1023.32,                 // Dinero
      10                       // Cantidad
    },
    { // Proveedor
      { "Daniel", "Hernandez" },// Persona
      "Lámparas",               // Desea Vender
      23,                       // Cantidad
      15.0                      // Precio c/u
    }
  };
  
  cout
    << "El id de venta es " << venta.id << endl
    << "Nombre del cliente " << venta.cliente.info.nombre << ", " << venta.cliente.info.apellido << endl
    << "    desea: " << venta.cliente.desea_comprar << endl
    << "    dinero disponible: " << venta.cliente.dinero << endl
    << "    cantidad deseada: " << venta.cliente.cantidad << endl << endl
    << "Nombre del proveedor: " << venta.proveedor.info.nombre << ", " << venta.proveedor.info.apellido << endl
    << "    desea vender: " << venta.proveedor.desea_vender << endl
    << "    precio c/u: " << venta.proveedor.precio << endl
    << "    cantidad disponible: " << venta.proveedor.cantidad << endl;
}
