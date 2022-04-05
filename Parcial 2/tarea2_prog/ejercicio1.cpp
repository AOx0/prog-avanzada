/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa que permita llevar un registro de contactos, agregar, ver, eliminar.
 */
#include <iostream>
#include <utility>

using namespace std;

struct Contacto {
  string nombre;
  string tel;
};

template <int CANTIDAD>
struct Contactos {
  int max;
  int cantidad;
  Contacto contactos[CANTIDAD];

  Contactos(): max(CANTIDAD), cantidad(0) {}

  void imprimir() const {
    if (cantidad == 0) { cout << "No hay contactos registrados\n"; return; }

    cout << "   Nombre                                  Número\n";
    for (int i=0; i<cantidad; i++) {
      Contacto r = contactos[i];

      string n = r.nombre;
      basic_string<char>::size_type len = n.length();

      for (basic_string<char>::size_type _=len; _<40; _++) n.push_back(' ');

      cout
          << i+1 << ((i+1<10) ? "  " : " ")
          << n
          << r.tel << "\t\t\n"
          ;
    }
  }

  void registrarContacto(Contacto & contacto) {
    if (cantidad == max) { cout << "No puedes agregar más\n"; return; }
    cantidad++;
    contactos[cantidad-1] = contacto;
  }


  void eliminarContacto(int aEliminar) {
    if (cantidad == 0) { cout << "No puedes eliminar más\n"; return; }

    cantidad--;

    int j = 0;
    for (int i=0; j<cantidad; i++) {
      if (i != aEliminar) {
        contactos[j] = move(contactos[i]);
        j++;
      }
    }

  }

};


int main() {
  Contactos<3> agenda = Contactos<3>();
  int op;
  while (true) {
    printf(
        "Opciones:\n"
        "    1. Ver agenda\n"
        "    2. Registrar contacto\n"
        "    3. Eliminar contacto\n"
        "    4. Salir\n"
    );

    do {
      cout << "Ingresa la opción: ";
      cin >> op;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (op < 0 || op > 4);

    switch (op) {
      case 1: {
        agenda.imprimir();
      }
        break;
      case 2: {
        if (agenda.cantidad == agenda.max) { cout << "No puedes agregar más\n"; break; };

        string nombre, tel;

        cout << "Ingresa el nombre: ";
        getline(cin, nombre);
        cout << "Ingresa el teléfono: ";
        getline(cin, tel);

        Contacto nuevo = {nombre, tel};
        agenda.registrarContacto(nuevo);
      }
        break;
      case 3: {
        int index;
        do {
          cout << "Ingresa el índice del contacto a eliminar: ";
          cin >> index;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (index < 0 || index > agenda.cantidad);

        agenda.eliminarContacto(index-1);
      }
        break;
      case 4:
        return 0;
    }
  }
}