#include <iostream>
#include <string.h>

using namespace std;

int main() {
  char nombre[2];
  
  strncpy(nombre, "123456789", 1);
  
  cout << nombre;
  
}
