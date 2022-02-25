/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer un programa en c++ que genere contraseñas seguras. Para esto debe tener las siguientes características:
    Longitud mínima de 8 caracteres.
    Caracteres alfanuméricos.
    Al menos un carácter especial.
    Al menos una mayuscula.
    Al menos un número.
    No puede tener dígitos iguales seguidos.
 */

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main() {
  char contrasenna[50] = {}, nuevo;
  int tamanno, toca;

  srand(time(nullptr));

  toca = rand() % 4;

  while (true) {
    cout << "Ingresa el tamaño de la contraseña (8-48): ";
    cin >> tamanno;

    if (tamanno > 48 || tamanno < 8) {
      cout << "Ingresa un tamaño válido!\n";
    } else {
      break;
    }
  }


  char mayus[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char minus[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char digt[11] = "0123456789";
  char special[10] = "*.,!#&$";

  for (int i=0; i<tamanno; i++) {
    switch (toca) {
      case 0: // Mayus
        nuevo = mayus[rand() % 26];
        break;
      case 1: // Minus
        nuevo = minus[rand() % 26];
        break;
      case 2: // numero
        nuevo = digt[rand() % 10];
        break;
      case 3: // Especial
        nuevo = special[rand() % 8];
        break;
      default:
        break;
    }

    contrasenna[i] = nuevo;
    toca = (toca + 1)%4;
  }

  cout << "Contraseña generada: " << contrasenna << endl;
}