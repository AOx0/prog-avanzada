/*
 Programación Avanzada -- Daniel Alejandro Osornio López

 Hacer un programa en c++ que permita calcular el RFC de una persona (sin homoclave).
 Se debe solicitar el nombre completo y la fecha de nacimiento.


 Notas:
    - error: use of undeclared identifier 'strupr'; did you mean 'strdup'? -- strupr no es parte del estandar ANSI.
    Así que tendré que usar toupper para cada carácter;

 > "These functions are not C standard functions. So it is implementation-defined whether they are supported or not."
      Referencia: (https://stackoverflow.com/questions/26327812/are-strupr-and-strlwr-in-string-h-part-of-the-ansi-standard)
*/

#include <iostream>
#include <string.h>


using namespace std;



int main() {
  int i_nombre = 0, i_mat = -1, i_pat = -1;
  char nombre[150], fecha_nacimiento[11], rfc[11], lazy[3];
  int numero_palabras;
  while (true) {
    cout << "Ingresa tu nombre COMPLETO (sin acentos): ";
    cin.getline(nombre, 150);

    for (int i=0; i<strlen(nombre); i++) {
      if (nombre[i] == ' ')
      {
        numero_palabras++;
        if (i_pat == -1) i_pat = i+1;
        else i_mat = i+1;
      }
    }

    if (numero_palabras < 3) {
      cout << "Debes ingresar nombre(s) y apellido paterno y materno\n";
    } else {
      break;
    }
  }

// Toca hacer cada uno mayúscula para que compile con g++ (Apple clang version 13.0.0 (clang-1300.0.29.30))
  for (int i=0; i<strlen(nombre); i++) {
    nombre[i] = toupper((unsigned char)nombre[i]);
  }


  while (true) {
    cout << "Ingresa tu fecha de nacimiento con el formato dd/MM/yyyy: ";
    cin >> fecha_nacimiento;

    bool valido = true;

    int d_mes = 0, d_anno = 0, d_dia = 0, etapa = 0;

    for (int i=0; i<strlen(fecha_nacimiento); i++) {
      if (fecha_nacimiento[i] == '/') {etapa++; continue; }

      // Una validación muy básica. No me da tiempo de implementar la verificación de meses y días válidos :c
      if (fecha_nacimiento[i] < '0' || fecha_nacimiento[i] > '9') { valido = false; continue; }

      switch (etapa) {
        case 0:
          d_dia++; break;
        case 1:
          d_mes++; break;
        default:
          d_anno++; break;
      }
    }

    if (!valido) {
      cout << "Debes ingresar solo caracteres válidos\n";
    } else if (d_dia == 2 && d_mes == 2 && d_anno == 4) {
      break;
    } else {
      cout << "Asegúrate de usar el formato adecuado: dd/MM/yyyy\n";
    }
  }


  std::cout << nombre[i_pat] << nombre[i_pat+1] << nombre[i_mat] << nombre[0] << fecha_nacimiento[8] << fecha_nacimiento[9];
  std::cout << fecha_nacimiento[3] << fecha_nacimiento[4] << fecha_nacimiento[0] << fecha_nacimiento[1] << "XXX" << endl;
}