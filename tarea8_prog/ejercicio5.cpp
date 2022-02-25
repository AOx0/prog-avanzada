/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer un programa en c++ que dada una frase comprobar si el balanceo de los paréntesis es correcto.
 Es decir, “(ccc(ccc)cc((ccc(c))))” es correcto, pero “)ccc(ccc)cc((ccc(c)))(“ no lo es, aunque tenga el
 mismo número de paréntesis abiertos que cerrados.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
  int abiertos = 0; int cerrados = 0;
  string frase;

  cout << "Ingresa la frase: ";
  cin >> frase;

  for (int i=0; i<frase.size(); i++) {
    if (frase[i] == ')') {
      cerrados++;
      if (abiertos < cerrados) {
        cout << "Paréntesis cerrado inválido en i: " << i <<endl;
        return 0;
      }
    }

    if (frase[i] == '(') {
      abiertos++;
    }
  }

  if (cerrados == abiertos) {
    cout << "Los paréntesis son válidos\n";
  }
}