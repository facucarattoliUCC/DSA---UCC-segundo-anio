/*DUDAS::
1) podria ver si la posicion del nro es impar declarando un array o/y vector?
2) linea 27 a 34:: porque en el manejo de excepcion cuando ingreso 0 me pide el
digito en ves de largarme el mensaje de error?
 */

#include <cassert>
#include <iostream>
#include <stdexcept>

// digito   123
// posicion 321
// posicion 210
//
// digito   12 3
// posicion 32 1
//
// digito   1 23
// posicion 3 21
//
// digit nro / 10   ultimo digito nro % 10
// posicion  posicion + 1

unsigned int digitosParesPosiImpar(unsigned int nro, unsigned int tamanioNro) {
  if (tamanioNro == 0) {
    throw std::invalid_argument("el tamanio debe ser mayor que 0");
  }

  // BaseCase
  if (nro < 10) {
    return tamanioNro % 2 != 0 && nro % 2 == 0;
  }

  int digitoActual = nro % 10;
  if (tamanioNro % 2 != 0 && digitoActual % 2 == 0) {
    return 1 + digitosParesPosiImpar(nro / 10, tamanioNro - 1);
  }
  return digitosParesPosiImpar(nro / 10, tamanioNro - 1);
}

unsigned int digitosParesPosiImparV2(unsigned int nro,
                                     unsigned int posicion = 1) {

  if (posicion == 0) {
    throw std::invalid_argument("la posicion debe ser mayor que 0");
  }

  bool es_posicion_impar = posicion % 2 != 0;
  bool es_digito_par = nro % 2 == 0;
  // BaseCase numero de un solo digito
  if (nro < 10) {
    return (es_digito_par && es_posicion_impar) ? 1 : 0;
  }

  if (es_posicion_impar && es_digito_par) {
    return 1 + digitosParesPosiImparV2(nro / 10, posicion + 1);
  }
  return digitosParesPosiImparV2(nro / 10, posicion + 1);
}

//          123
// posicion 123
void test_digitosParesPosiImpar() {
  assert(digitosParesPosiImpar(213, 3) == 1);
  assert(digitosParesPosiImpar(214, 3) == 2);
  assert(digitosParesPosiImpar(1111, 4) == 0);
  assert(digitosParesPosiImpar(1, 1) == 0);
  assert(digitosParesPosiImpar(2, 1) == 1);
  assert(digitosParesPosiImpar(0, 1) == 1);
  assert(digitosParesPosiImpar(12, 2) == 0);

  try {
    digitosParesPosiImpar(12, 0);
    assert(false);
  } catch (const std::invalid_argument &error) {
    assert(std::string(error.what()) == "el tamanio debe ser mayor que 0");
  }

  std::cout << "Tests digitosParesPosiImpar OK\n";
}

//          123
// posicion 321
void test_digitosParesPosiImparV2() {
  assert(digitosParesPosiImparV2(213) == 1);
  assert(digitosParesPosiImparV2(214) == 2);
  assert(digitosParesPosiImparV2(1111) == 0);
  assert(digitosParesPosiImparV2(1) == 0);
  assert(digitosParesPosiImparV2(2) == 1);
  assert(digitosParesPosiImparV2(0) == 1);
  assert(digitosParesPosiImparV2(12) == 1);

  try {
    digitosParesPosiImparV2(12, 0);
    assert(false);
  } catch (const std::invalid_argument &error) {
    assert(std::string(error.what()) == "la posicion debe ser mayor que 0");
  }

  std::cout << "Tests digitosParesPosiImparV2 OK\n";
}

int main() {
  test_digitosParesPosiImpar();
  test_digitosParesPosiImparV2();

  std::cout << "Ejercicio 6 - Guia 1: Recursividad\n";
  std::cout << "-----------------------------------\n";

  unsigned int nro, digitos;
  try {
    std::cout << "Ingrese un numero entero positivo: \n";
    std::cin >> nro;

    if (nro < 0) {
      throw std::invalid_argument("el nro tiene que ser mayor o igual que 0");
    }
  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << "\n";
    return 1;
  }

  try {
    std::cout << "Ingrese la cantidad de digitos del nro: \n";
    std::cin >> digitos;
    if (digitos == 0) {
      throw std::invalid_argument("digitos tiene que ser distinto de 0");
    }
  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << "\n";
    return 1;
  }

  try {
    unsigned int resultado = digitosParesPosiImpar(nro, digitos);
    std::cout << "El resultado es: " << resultado << "\n";
  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << "\n";
    return 1;
  }

  return 0;
}
