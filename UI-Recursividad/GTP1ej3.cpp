/*DUDAS
linea 12 :: cuando retorno la funcion recursiva, donde/como guarda el valor
calculado?
 */
#include <cassert>
#include <iostream>
#include <stdexcept>

int invertirNumero(int n, int invertido = 0) {
  if (n < 0) {
    throw std::invalid_argument("n debe ser mayor o igual que 0");
  }

  if (n == 0) {
    // return 0; SI RETORNO CERO MI RESULTADO SIEMPRE SERA CERO EN VEZ DEL
    // NUMERO INVERTIDO
    return invertido;
  }

  return invertirNumero(n / 10, invertido * 10 + n % 10);
}

int main() {

  assert(invertirNumero(123) == 321);
  assert(invertirNumero(12) == 21);
  assert(invertirNumero(1) == 1);
  assert(invertirNumero(102) == 201);
  assert(invertirNumero(100) == 1);
  assert(invertirNumero(10020) == 2001);
  assert(invertirNumero(0) == 0);

  std::cout << "Tests OK!\n";

  std::cout << "Ejercicio 3 - Guia 1: Recursividad\n";
  // std::cout << "-----------------------------------\n";
  //
  // int nro, invertido = 0;
  //
  // std::cout << "Ingrese el numero que desea invertir: \n";
  // std::cin >> nro;
  //
  // unsigned int nroInvertido = invertirNumero(nro);
  //
  // std::cout << "El numero a invertir es: " << nro << std::endl;
  // std::cout << "El numero invertido es: " << nroInvertido << std::endl;

  return 0;
}
