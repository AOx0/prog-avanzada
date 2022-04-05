/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa que permita llevar un registro de contactos, agregar, ver, eliminar haciendo uso de memoria dinámica
 */
#include <iostream>
#include <utility>

using namespace std;

struct Contacto {
  string nombre;
  string tel;
};

struct Contactos {
  int cantidad;
  Contacto * contactos;

  ~Contactos() {
    delete [] contactos;
  }

  Contactos(): cantidad(0), contactos(new Contacto[0]) {};

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
    cantidad++;

    Contacto * viejo = contactos;
    contactos = new Contacto[cantidad];

    for (int i=0; i<cantidad-1; i++) {
      contactos[i] = viejo[i];
    }

    contactos[cantidad-1] = contacto;

    delete [] viejo;
  }


  void eliminarContacto(int aEliminar) {
    cantidad--;

    Contacto * nuevo = new Contacto[cantidad];

    int j = 0;
    for (int i=0; j<cantidad; i++) {
      if (i != aEliminar) {
        nuevo[j] = move(contactos[i]);
        j++;
      }
    }

    delete [] contactos;
    contactos = nuevo;

  }

};


int main() {
  Contactos agenda = Contactos();
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