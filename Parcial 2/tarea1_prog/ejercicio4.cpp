/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que simule el funcionamiento de una máquina de venta de refrescos.
  Se debe contar con estructuras que almacenan el nombre del producto, la cantidad disponible y el precio.
  El usuario puede seleccionar una bebida y se debe validar la existencia y realizar la venta.
*/

#include <iostream>
using namespace std;

struct Refresco {
  string nombre;
  double precio;
  double cantidad;
};

struct Maquina {
public:
  int cantidad;
  Refresco * refrescos;

  ~Maquina() {
    delete [] refrescos;
  }

  Maquina(): cantidad(0), refrescos(nullptr) {};

  void imprimir() const {
    cout << "   Producto                                Cant\t\tPrecio\n";
    for (int i=0; i<cantidad; i++) {
      Refresco r = refrescos[i];

      string n = r.nombre;
      basic_string<char>::size_type len = n.length();

      for (basic_string<char>::size_type _=len; _<40; _++) n.push_back(' ');

      cout
          << i+1 << ((i+1<10) ? "  " : " ")
          << n
          << r.cantidad << "\t\t"
          << r.precio << "\n"
          ;
    }
  }

  void registrarRefresco(Refresco & refresco) {
    cantidad++;

    Refresco * viejo = refrescos;
    refrescos = new Refresco[cantidad];

    for (int i=0; i<cantidad-1; i++) {
      refrescos[i] = viejo[i];
    }

    refrescos[cantidad-1] = refresco;

    delete [] viejo;
  }

  void restarUno(int i) {
    refrescos[i].cantidad--;

    if (refrescos[i].cantidad == 0) {
      this->eliminarRefresco(i);
    }
  }

  void eliminarRefresco(int aEliminar) {
    cantidad--;

    Refresco * nuevo = new Refresco[cantidad];

    int j = 0;
    for (int i=0; j<cantidad; i++) {
      if (i != aEliminar) {
        nuevo[j] = move(refrescos[i]);
        j++;
      }
    }

    delete [] refrescos;
    refrescos = nuevo;

  }
};

int main() {

  int cantidad = 0;
  Maquina maquina = Maquina();

  do {
    cout << "Ingresa el número de refrescos: ";
    cin >> cantidad;
    cin.ignore(numeric_limits <streamsize>::max(), '\n');
  } while (cantidad < 2);

  for (int i=0; i<cantidad; i++) {
    string nombre;
    cout << "Ingresa el nombre del producto: ";
    getline(cin, nombre);
    Refresco nuevo_refresco = {nombre, (double)(rand() % 20 + 10),(double)(rand() % 10 + 3)};
    maquina.registrarRefresco(nuevo_refresco);
  }

  while (true) {
    maquina.imprimir();

    uint16_t opcion;

    bool valido = false;
    do {
      cout << "Ingresa el número de la bebida que deseas (o "<< maquina.cantidad+1 << " para salir): ";
      cin >> opcion;

      if (opcion == maquina.cantidad+1) goto end;

      if (opcion > 0 && opcion <= maquina.cantidad) valido = true;
      else {
        cout << "Ingresa un número de refresco válido\n";
      }
    } while (!valido);

    opcion--;
    maquina.restarUno(opcion);
    cout << "Por un \"" << maquina.refrescos[opcion].nombre << "\" la cantidad a pagar es: $" << maquina.refrescos[opcion].precio << "\n";
    cout << "Gracias por su compra\n";
  }

  end:
    return 0;

}
