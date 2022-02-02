/*
    Daniel Alejandro Osornio López -- Programación Avanzada

    Hacer un programa en C++ que lea un número entero por el teclado y determinar si es negativo.
*/

#include <iostream>

int main() {
    std::int64_t numero;

    std::cout << "Ingresa un número: ";
    std::cin >> numero;

    std::cout << "El número" << (numero < 0 ?  " " : " no ") << "es negativo" << std::endl;

    return 0;
}
