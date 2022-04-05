/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que permita realizar las votaciones de una elección. Se debe tener candidatos,
  permitir votar y finalmente dar un ganador.
 */
#include <iostream>
#include <utility>

using namespace std;

struct Candidato {
  string nombre;
  int votos;
};

struct Candidatos {
  Candidato * candidatos;
  int cantidad;

  ~Candidatos() {
    delete [] candidatos;
  }

  Candidatos(): candidatos(new Candidato[0]), cantidad(0) {};

  void mostrar_candidatos(bool mostrar_votos = false, bool indent = false, int filtrar = -1) {


    for (int i=0; i<cantidad; i++) {
      int votos = candidatos[i].votos;
      string nombre = candidatos[i].nombre;

      if (filtrar != -1 && votos != filtrar)  continue;

      std::cout << (indent ? "    " : "") << i+1 << ". " << nombre;

      if (mostrar_votos) {
        std::cout << "  --  Votos: " << votos;
      }

      std::cout << "\n";
    }
  }

  void registrarCandidato(string nombre) {

    Candidato * nuevo = new Candidato[cantidad+1];

    for (int i=0; i<cantidad; i++) {
      nuevo[i] = move(candidatos[i]);
    }

    Candidato nuevo_c = { nombre, 0 };
    nuevo[cantidad] = nuevo_c;

    delete [] candidatos;
    candidatos = nuevo;
    cantidad++;
  }
};

int main(){

  Candidatos candidatos = Candidatos();

  int grande = 0, ganadores = 1, numero;

  cout << "Ingresa el número de candidatos: ";
  cin >> numero;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int i=0; i<numero; i++) {
    string nombre;
    cout << "Ingresa el nombre del candidato: ";
    getline(cin, nombre);
    candidatos.registrarCandidato(nombre);
  }

  std::cout << "Para terminar de capturar datos ingresa el número 0 en lugar de un voto\n";

  while (true) {

    int voto;
    bool valido = false;

    std::cout << "Ingresa tu voto. Candidatos:\n";
    candidatos.mostrar_candidatos(false, true);

    do {
      std::cout << "Ingresa tu elección: ";
      std::cin >> voto;

      if (voto < 0 || voto > numero) std::cout << "Voto inválido, vuelva a tratar.\n";
      else valido = true;

    } while (!valido);

    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    if (voto == 0) break;
    Candidato * elegido = &candidatos.candidatos[voto-1];
    elegido->votos += 1;

    if (elegido->votos > grande) {
      ganadores = 1;
      grande = elegido->votos;
    } else if (grande == elegido->votos) ganadores++;
  }

  std::cout << "Resultados:\n";
  candidatos.mostrar_candidatos(true, true);


  if (ganadores != 1) std::cout << "\nEmpate entre " << ganadores << " personas con "<< grande << " votos:\n";
  else std::cout << "Tenemos un ganador con "<< grande << " votos:\n";

  candidatos.mostrar_candidatos(false, true, grande);

}