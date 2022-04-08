/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa que permita llevar un registro de contactos, agregar, ver, eliminar.
 */
#include <cstddef>
#include <iostream>
#include <ostream>
#include <utility>
#include <chrono>
#include <thread>

using namespace std;

struct Coche {
  string modelo;
  double gasolina;
  double km_recorridos;
};

struct Persona {
  string nombre;
  string apellido;
  double dinero;
  bool tieneCoche;
  Coche coche;
};

Persona crearPersona();
Coche crearCoche();
void ponerGasolina(Persona &, double);
void avanzarCoche(Coche &, int);

Persona crearPersona() {
  string nombre, apellido;
  cout << "Ingresa el nombre de la persona: ";
  getline(cin, nombre);
  
  cout << "Ingresa el apellido de la persona: ";
  getline(cin, apellido);
  
  double dinero;
  cout << "Ingresa la cantidad de dinero que tiene " << nombre << ": ";
  cin >> dinero;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  
  Coche null = {"", 0,0 };
  
  Persona persona = {
    nombre, 
    apellido,
    dinero,
    false,
    null
  };
  
  return persona;
}

Coche crearCoche() {
  string modelo;
  cout << "Ingresa el modelo del vehículo: ";
  getline(cin, modelo);
  
  Coche nuevo_coche = { modelo, 0, 0 };
  
  return nuevo_coche;
}

void avanzarCoche(Coche & coche, int tiempo) {
  for (int i=1; i<=tiempo*2; i++) {
    cout << "Avanzando "<< i <<"!\n";
    
    if (coche.gasolina == 0) {
      cout << "No queda gasolina para seguir avanzando!\n";
      break;
    }    
    coche.km_recorridos += 10;
    coche.gasolina -= 2.5;
    this_thread::sleep_for(chrono::milliseconds(250));
  }
}

void ponerGasolina(Persona & persona, double cantidad) {
  persona.coche.gasolina += cantidad;
  persona.dinero -= cantidad * 15;
}

void mostrarInfo(Coche & coche) {
  cout
    << "Modelo: " << coche.modelo << endl
    << "    Gasolina disponible: " << coche.gasolina << endl
    << "    Kilometros recorridos: " << coche.km_recorridos << endl
  ;
}



int main() {
  bool ya_registrado = false;
  Persona persona;
  Coche coche;
  while (1) {
    printf(
      "Menu:\n"
      "    1. Ingresar datos\n"
      "    2. Registrar coche\n"
      "    3. Poner gasolina\n"
      "    4. Usar carro\n"
      "    5. Mostrar información del coche\n"
      "    6. Cambiar de coche\n"
      "    7. Trabajar (dinero = horas * 200)\n"
      "    8. Mostrar información persona\n"
      "    9. Salir\n"
    );
  
    int opcion;
    do {
      cout << "Ingresa la opción: ";
      cin >> opcion;
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while ( opcion < 1 || opcion > 9);
  
    if (opcion == 9) return 0;
    
    if (opcion > 1 && !ya_registrado) {
      cout << "Primero registra al usuario con la opción 1\n";
      continue;
    }
    
    if (opcion >= 3 && opcion <= 6 && !persona.tieneCoche) {
      cout << "Primero registra un coche con la opción 4\n";
      continue;
    }
    
    switch (opcion) {
      case 1: {
        persona = crearPersona();
        ya_registrado = true;
      }
        break;
      case 2: {
        coche = crearCoche();
        persona.coche = coche;
        persona.tieneCoche = true;
      }
        break;
      case 3: {
        double cantidad;
        cout << "Ingresa la cantida de litros a poner: ";
        cin >> cantidad;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        ponerGasolina(persona, cantidad);
      }
        break;
      case 4: {
        int tiempo;
        
        cout << "Ingresa la catidad de tiempo: ";
        cin >> tiempo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        avanzarCoche(persona.coche, tiempo);
      }
        break;
      case 5: {
        mostrarInfo(persona.coche);
      }  
        break;
      case 6: {
        coche = crearCoche();
        persona.coche = coche;
      }
        break;
      case 7: {
        int tiempo;
        cout << "Ingresa la cantidad de horas a trabajar (segundos a esperar): ";
        cin >> tiempo;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        persona.dinero += tiempo * 5;
        this_thread::sleep_for(chrono::milliseconds(1000 * tiempo));
      }
        break;
      case 8: {
        cout
          << "Nombre: " << persona.nombre << ", " << persona.apellido << endl
          << "Dinero: " << persona.dinero << endl;
        
        if (persona.tieneCoche) {
          cout << "Coche: " << persona.coche.modelo << endl;
        }
        
      }
        break;
    }
  }
}
