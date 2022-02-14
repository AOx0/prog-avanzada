/*
  Daniel Alejandro Osornio López -- Programación Avanzada

  Hacer un programa en c++ que realice la multiplicación de 2 matrices.
 */

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<vector<int> > generarMatrizAleatoria(int num_filas, int num_columnas) {
  vector<vector<int> >  matriz =  vector<vector<int> >();


  for (int i=0; i < num_filas; i++) {
    vector<int> fila = vector<int>();

    for (int j = 0; j < num_columnas; j++) {
      fila.push_back(rand() % 100);
    }

    matriz.push_back(fila);
  }

  return matriz;
}

void mostrarMatriz(vector<vector<int> > * matriz) {

  if (matriz->empty()) { return; }

  for (int i=0; i<matriz->size(); i++) {
    vector<int> fila = matriz->at(i);

    for (int j = 0; j < fila.size(); j++) {
      printf("%-5d", fila.at(j));
    }

    cout << "\n";
  }
}


vector<vector<int> > pedirMatriz() {

  std::cout << "Ingresa las filas con cada valor separado por un espacio e ingresa enter para terminarla.\nPara terminar deja una fila vacía:\n";
  string num;

  vector<vector<int> > matriz = vector<vector<int> >();

  // Cada que el usuario ingrese una nueva fila (delimitada con un enter)
  while (getline(cin, num, '\n')) {

    // Creamos un stream de entrada falso conteniendo el texto recibido por el primer getline() para poder analizar cada
    // conjunto de caracteres separados por espacio con otro getline()
    istringstream in(num);

    vector<int> fila = vector<int>();

    // Si la linea esta vacía se termina el proceso de pedir la matriz
    if (num.empty()) break;

    // Si no, a cada grupo de dígitos separados por un espacio se convierte a int usando stoi()
    // y se agrega al final de la fila
    while (getline(in, num, ' ')) {
      fila.push_back(stoi(num));
    }

    // Si se ingresa una fila de un tamaño distinto a la anterior se genera un error y se termina el programa
    if (!matriz.empty()) {
      if (matriz.at(matriz.size()-1).size() != fila.size()) {
        std::cout << "Error: Todas las filas deben ser del mismo tamaño\n";
        exit(0);
      }
    }

    // Cuando se termina de construir la fila, se agrega la misma a la matriz
    matriz.push_back(fila);
  }

  return matriz;
}

vector<vector<int> > multiplicar_matrices(const vector<vector<int> > * matriz1, const vector<vector<int> > * matriz2) {
  vector<vector<int> > resultado = vector<vector<int> >();



  if (matriz1->empty() || matriz2->empty() || matriz2->size() != matriz1->at(0).size()) {
    cout << "Error, ingresa matrices válidas";
    exit(0);
  }

  for (int fila_m1=0; fila_m1<matriz1->size(); fila_m1++) {
    vector<int> fila_resultado = vector<int>();

    for (int columna_m2=0;columna_m2<matriz2->at(0).size(); columna_m2++) {
      int suma = 0;

      for (int k=0; k<matriz1->at(0).size(); k++) {
        suma +=  matriz1->at(fila_m1).at(k) * matriz2->at(k).at(columna_m2);
      }

      fila_resultado.push_back(suma);
    }

    resultado.push_back(fila_resultado);
  }

  return resultado;
}

vector<vector<int> > arrayAVector(int * arreglo, int filas, int columnas) {
  vector<vector<int> > resultado = vector<vector<int> >();
  for (int fila=0; fila<filas; fila++ ) {
    vector<int> fila_resultado = vector<int>();
    for (int columna=0; columna<columnas; columna++) {
      fila_resultado.push_back(arreglo[fila*filas + columna]);
    }

    resultado.push_back(fila_resultado);
  }

  return resultado;
}

int main() {
  srand(time(NULL));

  // Método 1 con arreglos hard-coded
  /*
  int matriz1s[3][3] = {
      {1, 6, 0},
      {-1, 3, 1},
      {4, 6, 2}
  };

  int  matriz2s[3][3] = {
      {0, 4, 0},
      {2, 3, 1},
      {1, -2, 1}
  };

  vector<vector<int> > matriz1 = arrayAVector(*matriz1s, 3, 3);
  vector<vector<int> > matriz2 = arrayAVector(*matriz2s, 3, 3);
   */

  // Método 2 con una matriz aleatoria de tamaño específico
  /*
  vector<vector<int> > matriz1 = generarMatrizAleatoria(3, 2);
  vector<vector<int> > matriz2 = generarMatrizAleatoria(1, 3);
   */

  // Método 3 ingresando la matriz por la terminal
  vector<vector<int> > matriz1 = pedirMatriz();
  vector<vector<int> > matriz2 = pedirMatriz();

  cout << "\nPrimera matriz: \n";
  mostrarMatriz(&matriz1);

  cout << "\nSegunda matriz: \n";
  mostrarMatriz(&matriz2);

  cout << "\nResultado: \n";
  vector<vector<int> > resultado = multiplicar_matrices(&matriz1, &matriz2);

  mostrarMatriz(&resultado);

  return 0;
}