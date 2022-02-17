/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que permita manejar la información de habitantes de un complejo habitacional.
  El mismo posee 7 torres; a su vez cada torre posee 20 pisos y cada piso 6 departamentos.
  Se desea saber:
    - Cantidad total de habitantes del complejo
    - Cantidad promedio de habitantes por piso de cada torre
    - Cantidad promedio de habitantes por torre


    Notas:
      - Para entender cómo moverse por la memoria en una matriz de más de 2 dimensiones usé:
          https://stackoverflow.com/questions/14015556/how-to-map-the-indexes-of-a-matrix-to-a-1-dimensional-array-c

      - Podía hacer lo pedido en un solo bucle, pero decidí desglosar poco a poco los pasos que se realizaron con el edificio.
        Aunque significara muchos loops exageradamente similares.
*/

#include <iostream>

using namespace std;

/// El método que llena aleatoriamente la matriz con un valor positivo (está habitado (1)) o negativo (no está habitado (0))
/// \param complejo Apuntador a donde inicia el complejo en memoria
void popular_edificio_aleatoriamente(int * complejo) {
  for (int edificio=0; edificio<7; edificio++)
    for (int piso=0; piso<20; piso++)
      for (int depa=0; depa<6; depa++) {
        int * depa_ptr = complejo +  edificio * (7 * 21) + 7 * piso + depa;
        *depa_ptr = rand() % 2;
      }
}

/// El méetodo encargado de llenar con información los espacios diseñados para tener metadata de los edificios y pisos
/// Es decir:
///     complejo[edificio][20][0] -- Para almacenar el total en un edificio
///     complejo[edificio][piso][6] -- para almacenar el total en un piso
/// \param complejo Apuntador a donde inicia el complejo en memoria
void analizar_complejo(int * complejo) {
  for (int edificio=0; edificio<7; edificio++) {
    // Es lo mismo a complejo[edificio][20][0]
    int * edificio_ptr = complejo +  edificio * (7 * 21) + 7 * 20;

    for (int piso=0; piso<20; piso++) {
      // Es lo mismo a complejo[edificio][piso][6]
      int * acum_ptr = complejo +  edificio * (7 * 21) + 7 * piso + 6;

      for (int depa=0; depa<6; depa++) {
        // Es lo mismo a complejo[edificio][piso][depa]
        int * depa_ptr = complejo +  edificio * (7 * 21) + 7 * piso + depa;
        if (*depa_ptr == 1) *acum_ptr += 1;
      }

      *edificio_ptr += *acum_ptr;
    }
  }
}

/// Procedimiento encargado de mostrar toda la información del arreglo.
/// \param complejo Apuntador a donde inicia el complejo en memoria
void mostrar_info(int * complejo) {
  for (int edificio=0; edificio<7; edificio++) {
    std::cout << "Edificio " << edificio << "\n" ;
    // Es lo mismo a complejo[edificio][20][0]
    int * edificio_ptr = complejo +  edificio * (7 * 21) + 7 * 20;

    for (int piso=0; piso<20; piso++) {
      printf("Piso %-2d: ", piso);
      // Es lo mismo a complejo[edificio][piso][6]
      int * acum_ptr = complejo +  edificio * (7 * 21) + 7 * piso + 6;

      for (int depa=0; depa<6; depa++) {
        // Es lo mismo a complejo[edificio][piso][depa]
        int * depa_ptr = complejo +  edificio * (7 * 21) + 7 * piso + depa;

        std::cout << "(" << depa+1 << ": " << (*depa_ptr == 1 ? "Si" : "No") << ") ";
      }

      std::cout << " --  Total: "<< *acum_ptr << " (almacenado en "<< acum_ptr << ")\n";
    }

    std::cout << "Total del edificio "<< edificio << ": "  <<  *edificio_ptr  << " (almacenado en "<< edificio_ptr << ")" << endl;
  }
}

int main(){

  srand(time(nullptr));

  // Un departamento extra para almacenar información de los 6 departamentos del piso (el total)
  // Un piso extra para almacenar información de los 21 pisos (el total)
  // Para asegurarme de la continuidad en memoria uso un espacio unidimensional que ocuparé como tridimensional
  int complejo[7 * 21 * 7] = {};
  string lazy; // Para poder hacer una especie de pausa

  // Si mostramos el complejo está vacío
  mostrar_info(&complejo[0]);

  std::cout << "\nInformación del edificio, aún sin popular (está vacío)\n";
  std::cout << "Ingrese lo que sea para continuar: ";
  std::cin >> lazy;

  // Populamos el edificio
  popular_edificio_aleatoriamente(&complejo[0]);


  // Si mostramos el complejo está lleno pero aún no procesado
  mostrar_info(&complejo[0]);

  std::cout << "\nInformación del edificio, populado pero no analizado (nótese en las direcciones que almacenan totales)\n";
  std::cout << "Ingrese lo que sea para continuar: ";
  std::cin >> lazy;

  // Si mostramos el complejo está vacío
  analizar_complejo(&complejo[0]);

  // Si mostramos el complejo está lleno y procesado
  mostrar_info(&complejo[0]);

  std::cout << "\nInformación del edificio, populado y analizado (nótese en las direcciones que almacenan totales)\n";
  std::cout << "Ingrese lo que sea para continuar: ";
  std::cin >> lazy;

  //Ahora podemos pasar a hacer los cálculos sin necesidad de recorrer cada departamento o piso,
  // reciclando el valor en complejo[edificio][20][0]
  int habitantes = 0;
  const double cantidad_pisos = 20 * 6;
  const double cantidad_edificios = 6;

  for (int edificio=0; edificio<7; edificio++) {
    // Es lo mismo a complejo[edificio][20][0]
    int * edificio_ptr = complejo +  edificio * (7 * 21) + 7 * 20;
    habitantes += *edificio_ptr;
  }

  std::cout << "\nPromedio de habitantes por piso: " << (habitantes/cantidad_pisos);
  std::cout << "\nPromedio de habitantes por edificio: " << (habitantes/cantidad_edificios);
  std::cout << "\nHabitantes totales: " << habitantes << endl;
}
