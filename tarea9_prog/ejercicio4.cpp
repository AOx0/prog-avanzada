/*
 Daniel Alejandro Osornio López -- Programación Avanzada

 Hacer una función en C++ que calcule un número elevado a otro.
 */

#include <iostream>

using namespace std;

double area_circulo(double radio);
double area_rectangulo(double base, double altura);
double area_triangulo(double base, double altura);

int main() {
  uint16_t num;

  while (true) {
    printf(
        "1. Área de un cuadrado\n"
        "2. Área de un rectángulo\n"
        "3. Área de un círculo\n"
        "4. Área de un triángulo\n"
    );
    cout << "Ingresa una opción: ";
    cin >> num;

    if (num >= 1 && 4 >= num) break;
  }

  switch (num) {
    case 1:
    {
      double lado;
      cout << "Ingresa la medida de un lado: ";
      cin >> lado;

      cout << "El área es " << area_rectangulo(lado, lado);
    }
      break;
    case 2:
    {
      double base;
      cout << "Ingresa la medida de la base: ";
      cin >> base;

      double altura;
      cout << "Ingresa la medida de la altura: ";
      cin >> altura;

      cout << "El área es " << area_rectangulo(base, altura);
    }
      break;
    case 3:
    {
      double r;
      cout << "Ingresa el radio del cículo: ";
      cin >> r;


      cout << "El área es " << area_circulo(r);
    }
      break;
    case 4:
    {
      double base;
      cout << "Ingresa la medida de la base: ";
      cin >> base;

      double altura;
      cout << "Ingresa la medida de la altura: ";
      cin >> altura;

      cout << "El área es " << area_triangulo(base, altura);
    }
      break;
  }
}

double area_circulo(double radio) {
  return 3.1416 * radio * radio;
}

double area_rectangulo(double base, double altura) {
  return base * altura;
}

double area_triangulo(double base, double altura) {
  return (base * altura)/2;
}