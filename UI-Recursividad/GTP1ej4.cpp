/*DUDAS:
1) Linea 38 a 46:: esta bien manejado el error? la asignacion de la f
calculoMayor y la muestra de su resultado deberia ir en el cuerpo del catch?

2)
como le asigno elementos a mi vector?

3) Cuando ejecuto el programa siempre me
imprime cero.
 */

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <vector>

int calculoMayor(std::vector<int> vector) {

  // CasoBase..
  // si el taminio es 0 significa que no hay elemento entonces que retorne 0...
  // si el taminio es 1 signicia que hay un elemento entonces que me retorne ese
  // elemento accediendo al vector en la unica posicion que tiene
  if (vector.size() == 0) {
    throw std::invalid_argument("Tamanio del vector debe ser mayor que 0");
  }

  // Si el vector tiene un elemento entonces que retorno al vector en la
  // posicion inicial
  if (vector.size() == 1) {
    return vector[0];
  }

  // Construccion recursividad
  int maximo = vector.back();
  vector.pop_back();
  int maximoR = calculoMayor(vector);
  return (maximo > maximoR ? maximo : maximoR);

  // De esta manera estoy haciendo llamado a f calculoMayor() dos veces.
  // Una llamada "int maximo = calculoMayor (tamanio-1,vector)". Otra llamada
  // "if (maximo > calculoMayor (tamanio-1,vector)" Esto hace que la
  // recursividaad se ejecute dos veces innecesariamente
  //  if (maximo > calculoMayor (tamanio-1,vector)){
  //      return maximo;
  //  }
  //  return vector[tamanio-1];
}

void test_calculoMayor() {
  {
    std::vector<int> a = {1, 2, 3};
    assert(calculoMayor(a) == 3);
  }

  {
    std::vector<int> a = {1, 2, 3, 1, 2};
    assert(calculoMayor(a) == 3);
  }

  {
    std::vector<int> a = {10, 2, 3, 1, 2};
    assert(calculoMayor(a) == 10);
  }

  {
    std::vector<int> a = {2};
    assert(calculoMayor(a) == 2);
  }

  try {
    std::vector<int> a;
    calculoMayor(a);
    assert(false);
  } catch (const std::invalid_argument &error) {
    assert(std::string(error.what()) ==
           "Tamanio del vector debe ser mayor que 0");
  }

  std::cout << "Tests OK\n";
}

int main() {
  test_calculoMayor();

  std::cout << "Ejercicio 4 - Guia 1: Recursividad\n";
  std::cout << "-----------------------------------\n";

  int tama, elemMayor, i;
  try {
    std::cout << "Ingrese el tamanio del vector: \n";
    std::cin >> tama;

    if (tama <= 0) {
      throw std::invalid_argument("el tamanio debe ser mayor que 0");
    }

  } catch (const std::invalid_argument &e) {
    std::cout << "Error: " << e.what() << "\n";
    return 1;
  }

  std::vector<int> miVector(tama);

  for (i = 0; i < tama; ++i) {
    int elem;
    std::cout << "Ingrese el valor para el elemento " << i << " del vector: ";
    std::cin >> elem;
    miVector[i] = elem;
  }
  elemMayor = calculoMayor(miVector);

  std::cout << "El elemento mayor es: " << elemMayor << "\n";

  return 0;
}
