/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que permita realizar las votaciones de una elección. Se debe tener candidatos,
  permitir votar y finalmente dar un ganador.
 */
#include <iostream>
#include <utility>

#define CANDIDATOS 5

using namespace std;

// Para facilitar la vida almaceno el string en esta estructura
struct Nombre {
public:
  string nombre;

  explicit Nombre(string nombre) : nombre(std::move(nombre)){};
};

void mostrar_candidatos(void ** matriz, bool mostrar_votos = false, bool indent = false, int filtrar = -1) {

  int j = 1;
  for (int i=0; i<CANDIDATOS; i++) {
    int * votos = (int *)(matriz[2 * i + 0]);
    Nombre * nombre = (Nombre *)matriz[2 * i + 1];

    if (filtrar != -1 && *votos != filtrar)  continue;

    std::cout << (indent ? "    " : "") << j << ". " << nombre->nombre;

    if (mostrar_votos) {
      std::cout << "  --  Votos: " << *votos;
    }

    std::cout << "\n";
    j++;
  }
}


int main(){

  int grande = 0, ganadores = 1;
  void * arreglo_apuntadores[CANDIDATOS][2] = {};
  const std::string candidatos[CANDIDATOS] = {"Pepe G", "Pedro F", "Alejandro H", "Sara W", "David L"};

  for (int i=0; i<CANDIDATOS; i++) {
    arreglo_apuntadores[i][0] = calloc(1, sizeof(uint32_t /*(unsigned int)*/));
    *(int *)(arreglo_apuntadores[i][0]) = 0;

    arreglo_apuntadores[i][1] = calloc(1, sizeof(Nombre));
    *(Nombre *)(arreglo_apuntadores[i][1]) = Nombre(candidatos[i]);
  }

  std::cout << "Para terminar de capturar datos ingresa el número 0 en lugar de un voto\n";

  while (true) {

    int voto;
    bool valido = false;

    std::cout << "Ingresa tu voto. Candidatos:\n";
    mostrar_candidatos(arreglo_apuntadores[0], false, true);

    do {
      std::cout << "Ingresa tu elección: ";
      std::cin >> voto;

      if (voto < 0 || voto > CANDIDATOS) std::cout << "Voto inválido, vuelva a tratar.\n";
      else valido = true;

    } while (!valido);

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    if (voto == 0) break;
    int * elegido = (int *)(arreglo_apuntadores)[0][(voto-1) * 2 + 0];
    *elegido += 1;

    if (*elegido > grande) {
      ganadores = 1;
      grande = *elegido;
    } else if (grande == *elegido) ganadores++;
  }

  std::cout << "Resultados:\n";
  mostrar_candidatos(arreglo_apuntadores[0], true, true);


  if (ganadores != 1) std::cout << "\nEmpate entre " << ganadores << " personas con "<< grande << " votos:\n";
  else std::cout << "Tenemos un ganador con "<< grande << " votos:\n";

  mostrar_candidatos(arreglo_apuntadores[0], false, true, grande);

  // Limpiamos la memoria usada.
  for (int i=0; i<CANDIDATOS; i++) {
    free(arreglo_apuntadores[i][0]);
    free(arreglo_apuntadores[i][1]);
  }
}