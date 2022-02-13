/*
  Daniel Alejandro Osornio López
  
  Hacer un programa en C++ que permita agendar citas médicas
  (general, dentista, especialista, nutrición, etc.).
*/

#include <iostream>

int main() {
  std::uint16_t opcion;
  std::string tipo_medico;
  
  srand(time(NULL));

  std::cout
    << "Puedes agendar:\n"
    << "1. Cita con médico general\n"
    << "2. Cita con dentista\n"
    << "3. Cita con nutriólogo\n"
  ;
  
  std::cout << "Ingresa el tipo de cita que deseas: ";
  std::cin >> opcion;
  
  switch (opcion) {
    case 1: tipo_medico = "médico general"; break;
    case 2: tipo_medico = "dentista"; break;
    case 3: tipo_medico = "nutriólogo"; break;
    default: 
      std::cout << "Opción inválida";
      return 0;
  }
  
  std::cout << "Listo. tu cita con el "<<tipo_medico << " es el " << rand() % 30 << "/" << rand() % 12 << "/2022\n";  

  return 0;
}