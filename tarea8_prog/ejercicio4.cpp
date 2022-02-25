/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer un programa en c++ que dada una frase de tamaño máximo N, determine si es un palíndromo o no.
 Un palíndromo es una frase que, atendiendo sólo a sus letras e ignorando los espacios, acentos, signos de puntuación y
 tipo de letra (mayúscula o minúscula) expresa lo mismo leída de izquierda a derecha que de derecha a izquierda.
 “dábale arroz a la zorra el abad”.

 Notas:
    - No pude usar strrev. No es una función estándar
 */

#include <iostream>
#include <string>
#include <string.h>
#include <regex>

using namespace std;


int main() {
  string frase, frase_sin_espacios;
  cout << "Ingresa la frase: ";

  getline(cin, frase);

  // Es la manera más facil :c  -- https://stackoverflow.com/questions/4643512/replace-substring-with-another-substring-c
  char acentuados[10][3] = {"á", "é", "í", "ó", "ú", "Á", "É", "Í", "Ó", "Ú"};
  char normal[5][2] = {"a", "e", "i", "o", "u"};

  for (int i=0; i<5; i++) {
    frase = std::regex_replace(frase, std::regex(normal[i]), normal[i]);
    frase = std::regex_replace(frase, std::regex(normal[i+5]), normal[i]);
  }

  for (int i=0; i<frase.size(); i++) {
    if (frase[i] != ' ' && frase[i] != '.' && frase[i] != ',') {
      frase_sin_espacios.push_back(tolower(frase[i]));
    }
  }

  // strrev no es una función estandar. Toca hacerlo a mano
  string frase_reversed = string();

  for (int i=frase_sin_espacios.size()-1; i>=0; i--) {
    frase_reversed.push_back(frase_sin_espacios[i]);
  }


  cout << "La frase " << (frase_reversed == frase_reversed ? "si" : "no") << " es un palíndromo." << endl;
}