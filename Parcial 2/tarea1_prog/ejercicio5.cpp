/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa que permita tener un registro de libros, consultar por autor, eliminar, etc.  
*/
#include <iostream>
#include <utility>

#define NOMBRE 123134342
#define AUTOR  423454242

using namespace std;

struct Libreria {
  string nombre;
  string autor;
};

struct Librerias {
  int cantidad;
  Libreria * libros;

  ~Librerias() {
    delete [] libros;
  }

  Librerias(): cantidad(0), libros(new Libreria[0]) {};

  void imprimir() const {
    if (cantidad == 0) { cout << "No hay libros registrados\n"; return; }

    cout << "   Nombre                                  Autor\n";
    for (int i=0; i<cantidad; i++) {
      Libreria r = libros[i];

      string n = r.nombre;
      basic_string<char>::size_type len = n.length();

      for (basic_string<char>::size_type _=len; _<40; _++) n.push_back(' ');

      cout
        << i+1 << ((i+1<10) ? "  " : " ")
        << n
        << r.autor << "\t\t\n"
      ;
    }
  }

  void registrarLibreria(Libreria & contacto) {
    cantidad++;

    Libreria * viejo = libros;
    libros = new Libreria[cantidad];

    for (int i=0; i<cantidad-1; i++) {
      libros[i] = viejo[i];
    }

    libros[cantidad-1] = contacto;

    delete [] viejo;
  }

  template<int T>
  int buscarPor(string & nombre) {
    for (int i=0; i<cantidad; i++) {
      string campo;
      if (T == NOMBRE) campo = libros[i].nombre;
      else if (T == AUTOR) campo = libros[i].autor;

      if (campo == nombre) return i;
    }

    return -1;
  }


  void eliminarLibreria(int aEliminar) {
    cantidad--;

    Libreria * nuevo = new Libreria[cantidad];

    int j = 0;
    for (int i=0; j<cantidad; i++) {
      if (i != aEliminar) {
        nuevo[j] = move(libros[i]);
        j++;
      }
    }

    delete [] libros;
    libros = nuevo;

  }

};


int main() {
  Librerias libreria = Librerias();
  int op;
  while (true) {
    printf(
        "Opciones:\n"
        "    1. Ver libros\n"
        "    2. Registrar libro\n"
        "    3. Eliminar libro\n"
        "    4. Buscar por nombre\n"
        "    5. Salir\n"
    );

    do {
      cout << "Ingresa la opción: ";
      cin >> op;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (op < 0 || op > 5);

    switch (op) {
      case 1: {
        libreria.imprimir();
      }
        break;
      case 2: {
        string nombre, autor;
        cout << "Ingresa el nombre: ";
        getline(cin, nombre);
        cout << "Ingresa el autor: ";
        getline(cin, autor);

        Libreria nuevo = {nombre, autor};
        libreria.registrarLibreria(nuevo);
      }
        break;
      case 3: {
        int index;
        do {
          cout << "Ingresa el índice del libro a eliminar: ";
          cin >> index;
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } while (index < 0 || index > libreria.cantidad);

        libreria.eliminarLibreria(index-1);
      }
        break;
      case 4: {
        string campo;
        cout << "Ingresa el nombre del libro a buscar: ";
        getline(cin, campo);

        int index = libreria.buscarPor<NOMBRE>(campo);
        if (index == -1) {
          cout << "No se encontró el libro con dicho nombre\n";
        } else {
          cout << "ID (Index): " << index+1 << " ––– Nombre: " << libreria.libros[index].nombre << " by " << libreria.libros[index].autor << endl;
        }
      }
        break;
      case 5:
        return 0;
    }
  }
}