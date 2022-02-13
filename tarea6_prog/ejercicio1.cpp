#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generarMatriz(int filas, int columnas) {
  vector<vector<int>>  matriz =  vector<vector<int>>();


  for (int i=0; i<filas; i++) {
    vector<int> fila = vector<int>();

    for (int j = 0; j < columnas; j++) {
      fila.push_back(rand() % 100);
    }

    matriz.push_back(fila);
  }

  return matriz;
}

void mostrarMatriz(vector<vector<int>> * matriz) {

  if (matriz->empty()) { return; }

  for (int i=0; i<matriz->size(); i++) {
    vector<int> fila = matriz->at(i);

    for (int j = 0; j < fila.size(); j++) {
      std::cout << fila.at(j) << "\t";
    }

    std::cout << "\n";
  }
}

vector<vector<int>> multiplicar_matrices(const vector<vector<int>> * matriz1, const vector<vector<int>> * matriz2) {
  vector<vector<int>> resultado = vector<vector<int>>();



  if (matriz1->empty() || matriz2->empty() || matriz2->size() != matriz1->at(0).size()) {
    std::cout << "Error, ingresa matrices válidas";
    exit(0);
  }


  for (int i=0; i<matriz1->size(); i++) {
    vector<int> fila_resultado = vector<int>();


    for (int j=0; j<matriz1->size(); j++) {
      int suma = 0;
      for (int k=0; k<matriz2->size(); k++) {
        suma +=  matriz1->at(i).at(k) * matriz2->at(k).at(j);
      }

      fila_resultado.push_back(suma);
    }

    resultado.push_back(fila_resultado);
  }

  return resultado;
}

vector<vector<int>> arrayAVector(int * arreglo, int filas, int columnas) {
  vector<vector<int>> resultado = vector<vector<int>>();
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

  int matriz1[3][3] = {
      {1, 6, 0},
      {-1, 3, 1},
      {4, 6, 2}
  };

  int  matriz2[3][3] = {
      {0, 4, 0},
      {2, 3, 1},
      {1, -2, 1}
  };

  /*
  vector<vector<int>> matriz1 = generarMatriz(3, 2);
  vector<vector<int>> matriz2 = generarMatriz(1, 3);
   */
  vector<vector<int>> matriz11 = arrayAVector(*matriz1, 3, 3);
  vector<vector<int>> matriz22 = arrayAVector(*matriz2, 3, 3);

  std::cout << "\nPrimera matriz: \n";
  mostrarMatriz(&matriz11);

  std::cout << "\nSegunda matriz: \n";
  mostrarMatriz(&matriz22);

  std::cout << "\nResultado: \n";
  vector<vector<int>> resultado = multiplicar_matrices(&matriz11, &matriz22);

  mostrarMatriz(&resultado);



  return 0;
}