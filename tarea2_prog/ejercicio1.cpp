/*
    Daniel Alejandro Osornio López -- Programación Avanzada
    
    Hacer un programa en C++ que lea un número por el teclado y determinar si tiene tres dígitos.
*/

#include <iostream>

int main() {
    std::int64_t numero;

    std::cout << "Ingresa un número: ";
    std::cin >> numero;

    std::cout << "El número" << (numero > 99 ?  " " : " no ") << "tiene más de 3 digitos" << std::endl;

    return 0;
}

