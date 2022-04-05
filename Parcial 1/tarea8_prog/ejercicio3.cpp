/*
  Daniel Alejandro Osornio López -- Programación avanzada

  Hacer un programa en c++ que lea una frase y determine que caracteres se encuentran repetidos.
  Se debe utilizar un vector en donde se almacene la cantidad de veces que se repite cada una de las letras.


  Funciona así:
      Ingresa una oración de hasta 300 caracteres: hhooollaa me llamo pedrroo
      Repetido: hh
      Repetido: ooo
      Repetido: ll
      Repetido: aa
      Repetido: ll
      Repetido: rr
      Repetido: oo
 */

#include <string>
#include <string.h>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  char texto[101] = {};

  cout << "Ingresa una oración de hasta 300 caracteres: ";
  cin.getline(texto, 100);

  bool active = false;
  vector<string> ocurrences = vector<string>();
  for (int i=0; i<strlen(texto); i++) {
    if (texto[i-1] == texto[i] && !active) {
      active = true;
      string a = string();
      a.push_back(texto[i]);
      a.push_back(texto[i]);
      ocurrences.push_back(move(a));
    } else if (texto[i-1] == texto[i] && active) {
      ocurrences[ocurrences.size()-1].push_back(texto[i]);
    } else {
      active = false;
    }
  }

  for (int i=0; i<ocurrences.size(); i++) {
    cout << "Repetido: " << ocurrences[i] << "\n";
  }
}