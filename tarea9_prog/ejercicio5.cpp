/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer un programa en C++ que lea diez números por teclado y escriba en letras sólo los que estén comprendidos entre el 1 y el 10.
 */

#include <iostream>

using namespace std;

void imprimir_num();

int main() {
  imprimir_num();
}


void imprimir_num() {
  int num;
  for (int i=0; i<10; i++) {
    cout << "Num " << i << ": ";
    cin >> num;

    if (num >= 1 && num <= 10) {
      cout << "Es el número ";

      switch (num) {
        case 1:
          cout << "uno";
          break;
        case 2:
          cout << "dos";
          break;
        case 3:
          cout << "tres";
          break;
        case 4:
          cout << "cuatro";
          break;
        case 5:
          cout << "cinco";
          break;
        case 6:
          cout << "seis";
          break;
        case 7:
          cout << "siete";
          break;
        case 8:
          cout << "ocho";
          break;
        case 9:
          cout << "nueve";
          break;
        case 10:
          cout << "diez";
          break;
        default:
          break;
      }

      cout << "\n";
    }
  }
}
