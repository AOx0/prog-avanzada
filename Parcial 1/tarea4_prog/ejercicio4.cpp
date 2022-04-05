/*
  Daniel Alejandro Osornio López
  
  Hacer un programa en C++ que permite convertir entre decimal, Hexa y binario.
*/

#include <math.h>
#include <iostream>

std::string * decimalABinario(std::uint64_t num);
std::uint64_t binarioADecimal(std::string num);
std::string * decimalAHexa(std::uint64_t num);
std::uint64_t hexaADecimal(std::string num);

int main() {
  std::uint16_t opcion;

  std::cout
      << "1. Decimal a binario\n"
      << "2. Decimal a hexadecimal\n"
      << "3. Binario a decimal\n"
      << "4. Binario a hexadecimal\n"
      << "5. Hexadecimal a decimal\n"
      << "6. Hexadecimal a binario\n"
      ;

  std::cout << "Ingresa la opción que deseas: ";
  std::cin >> opcion;

  switch (opcion) {
    case 1:
    {
      std::uint64_t num;

      std::cout << "Ingresa el número: ";
      std::cin >> num;
      std::string * resultado = decimalABinario(num);

      std::cout << *resultado << "\n";
    }
      break;
    case 2:
    {
      std::uint64_t num;

      std::cout << "Ingresa el número: ";
      std::cin >> num;
      std::string * resultado = decimalAHexa(num);

      std::cout << *resultado << "\n";

      delete resultado;
    }
      break;
    case 3:
    {
      std::string num;

      std::cout << "Ingresa el número en binario: ";
      std::cin >> num;
      std::uint64_t resultado = binarioADecimal(num);

      std::cout << resultado << "\n";
    }
      break;
    case 4:
    {
      std::string num;

      std::cout << "Ingresa el número en binario: ";
      std::cin >> num;
      std::uint64_t resultado_bin = binarioADecimal(num);
      std::string * resultado_hex = decimalAHexa(resultado_bin);

      std::cout << *resultado_hex << "\n";

      delete resultado_hex;
    }
      break;
    case 5:
    {
      std::string num;

      std::cout << "Ingresa el número en hexadecimal: ";
      std::cin >> num;
      std::uint64_t resultado = hexaADecimal(num);

      std::cout << resultado << "\n";
    }
      break;
    case 6:
    {
      std::string num;

      std::cout << "Ingresa el número en hexadecimal: ";
      std::cin >> num;
      std::uint64_t resultado_dec = hexaADecimal(num);
      std::string * resultado_bin = decimalABinario(resultado_dec);

      std::cout << *resultado_bin << "\n";

      delete resultado_bin;
    }
      break;
  }
  
  return 0;
}

std::uint64_t binarioADecimal(std::string num) {
  std::uint64_t n = 1, resultado = 0;
  for (int i=num.length()-1; i >= 0; i--) {
    resultado += num[i] == '0' ? 0 : n;
    n *= 2;
  }

  return resultado;
}

std::uint64_t hexaADecimal(std::string num) {
  std::uint64_t n = 1, resultado = 0, valor;
  for (int i=num.length()-1; i >= 0; i--) {
    switch (num[i]) {
      case 'A': valor = 10; break;
      case 'B': valor = 11; break;
      case 'C': valor = 12; break;
      case 'D': valor = 13; break;
      case 'E': valor = 14; break;
      case 'F': valor = 15; break;
      default:
        valor = num[i] - '0';
        break;
    }
    resultado += valor * n;
    n *= 16;
  }

  return resultado;
}

std::string * decimalABinario(std::uint64_t num) {
  std::string * resultado = new std::string("");
  std::uint64_t residuo, cociente = num;

  do {
    residuo = cociente%2;
    cociente = cociente/2;
    *resultado = (residuo == 1 ? "1" : "0") + *resultado;
  }
  while (cociente > 0);

  return resultado;
}

std::string * decimalAHexa(std::uint64_t num) {
  std::string * resultado = new std::string("");
  std::uint64_t residuo, cociente = num;

  do {
    residuo = cociente%16;
    cociente = cociente/16;
    std::string residuo_formateado = std::string("");

    if (residuo > 9) {
      switch (residuo) {
        case 10: residuo_formateado = "A"; break;
        case 11: residuo_formateado = "B"; break;
        case 12: residuo_formateado = "C"; break;
        case 13: residuo_formateado = "D"; break;
        case 14: residuo_formateado = "E"; break;
        case 15: residuo_formateado = "F"; break;
      }
    } else {
      residuo_formateado = std::to_string(residuo);
    }

    *resultado = residuo_formateado + *resultado;
  }
  while (cociente > 0);

  return resultado;
}