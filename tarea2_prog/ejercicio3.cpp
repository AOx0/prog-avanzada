/*
    Daniel Alejandro Osornio López -- Programación Avanzada

    Hacer un programa en C++ que lea un número entero positivo de dos dígitos y determinar a cuánto es la suma de sus dígitos.        
*/

#include <iostream>

bool esNumero(char digit) {
    return digit >= '0' && digit <= '9';
}

int main() {
    std::string numero;
    std::cout << "Ingresa un número: ";
    std::cin >> numero;

    bool caracteres = numero.length() == 2;
    bool digito1 = esNumero(numero[0]);

    if (caracteres && digito1 && esNumero(numero[1])) {
        std::cout << "La suma de los dígitos es: " << numero[0] + numero[1] - 2*'0';
    } else if (!caracteres) {
        std::cout << "Ingresa un número de solo dos dígitos";
    } else {
        std::cout << "Error: El " << (!digito1 ? "primer" : "segundo") << " carácter no es un dígito";
    }

    std::cout << std::endl;

    return 0;
}