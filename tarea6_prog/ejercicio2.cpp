/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que permita realizar las votaciones de una elección. Se debe tener candidatos,
  permitir votar y finalmente dar un ganador.
 */
#include <iostream>

int main(){

  const int TM = 5;

  int votos_empate[TM] = {0,0,0,0,0};
  std::string candidatos[TM] = {"Pepe G", "Pedro F", "Alejandro H","Sara W", "David L"};
  std::cout << "Para terminar de capturar datos ingresa el número 0 en lugar de un voto\n";

  while (true) {

    int voto;
    bool valido = false;

    std::cout << "Ingresa tu voto. Candidatos:\n";
    for (int i=0; i<TM; i++) std::cout << "    " << i+1 << ". " << candidatos[i] << "\n";

    do {
      std::cout << "Ingresa tu elección: ";
      std::cin >> voto;

      if (voto < 0 || voto>TM) std::cout << "Voto inválido, vuelva a tratar.\n";
      else valido = true;

    } while (!valido);

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    if (voto == 0) break;
    votos_empate[voto-1]++;
  }

  int grande = 0, ganadores = 1;
  std::cout << "Resultados:\n";
  for (int i=0; i<TM; i++) {
    if ( votos_empate[i] > grande) {
      ganadores = 1;
      grande = votos_empate[i];
    }

    else if (grande == votos_empate[i]) ganadores++;
    std::cout << "    " << candidatos[i] << ": " << votos_empate[i] << "\n";
  }

  if (ganadores != 1) std::cout << "Empate entre " << ganadores << " personas con "<< grande << " votos:\n";
  else std::cout << "Tenemos un ganador con "<< grande << " votos:\n";

  for (int i=0; i<TM; i++)
    if (votos_empate[i] == grande)
      std::cout <<  candidatos[i] << "\n";
}