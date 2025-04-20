#include <cassert>
#include <iostream>
#include <stdexcept> //Para usar std::runtime_error
#include <string>

int sumaRecursiva(int n) {

  if (n < 0) {
    throw std::invalid_argument("n debe ser mayor o igual que 0");
  }

  if (n == 0) {
    return 0;
  }
  if (n == 1) {
    return 1;
  }
  return n + sumaRecursiva(n - 1);
}

// 12 = 1 + 2+ 3 + 4 ...+ 12

int main() {
  assert(sumaRecursiva(1) == 1);
  assert(sumaRecursiva(2) == 3);
  assert(sumaRecursiva(3) == 6);
  assert(sumaRecursiva(0) == 0);

  try {
    sumaRecursiva(-1);
    assert(false);
  } catch (const std::invalid_argument &error) {
    assert(std::string(error.what()) == "n debe ser mayor o igual que 0");
  }

  std::cout << "Tests OK!\n";

  // std::cout << "Ejercicio 2 - Guia 1: Recursividad\n";
  // std::cout << "-----------------------------------\n";
  // int a;
  // try {
  //   std::cout << "Ingrese los numeros enteros a sumar recursivamente: \n";
  //   std::cin >> a;
  //   std::cout << "La suma de los primeros " << a
  //             << " numeros es: " << sumaRecursiva(a);
  // } catch (const std::exception &e) {
  //   std::cout << "Error: " << e.what() << std::endl;
  // }

  return 0;
}
