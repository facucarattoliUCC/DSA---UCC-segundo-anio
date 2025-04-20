/*DUDAS::
1) porque no me retorna el contador de las vocales?
2) los codigos comentados son los que intente escribir hasta que desisti. En que
falle? Cual fue la falla de mi razonamiento o logica?

 */
#include "Lista.h"
#include <cassert>
#include <cctype>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <string>

bool esVocal(char letter) {
  letter = tolower(letter);
  return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' ||
         letter == 'u';
}

int contarVocal(Lista<char> &lis1, char vo) {
  int cont = 0;
  for (int i = 0; i < lis1.getTamanio(); i++) {
    if (lis1.getDato(i) == vo) {
      cont++;
    }
  }
  return cont;
}

int contarVocalV2(std::string palabra, char vocal) {
  if (!esVocal(vocal)) {
    throw std::invalid_argument("vocal debe ser una vocal");
  }

  Lista<char> lista;

  for (std::size_t i = 0; i < palabra.size(); i++) {
    lista.insertarUltimo(palabra[i]);
  }

  int vocales = 0;
  for (int i = 0; i < lista.getTamanio(); i++) {
    if (tolower(lista.getDato(i)) == tolower(vocal)) {
      vocales++;
    }
  }

  return vocales;
}

void test_contarVocalV2() {

  assert(contarVocalV2("aabb", 'a') == 2);
  assert(contarVocalV2("aabbaa", 'a') == 4);
  assert(contarVocalV2("aabbaa", 'e') == 0);
  assert(contarVocalV2("", 'e') == 0);
  assert(contarVocalV2("a", 'a') == 1);
  assert(contarVocalV2("a", 'A') == 1);
  assert(contarVocalV2("aabbaa", 'A') == 4);

  try {
    assert(contarVocalV2("a", 'b') == 1);
    assert(false);
  } catch (const std::invalid_argument &error) {
    assert(std::string(error.what()) == "vocal debe ser una vocal");
  }

  std::cout << "Test contarVocalV2 OK\n";
}

void test_Lista() {
  {
    Lista<int> l1;
    l1.insertarUltimo(1);

    Lista<int> l2 = l1;

    assert(l1.getDato(0) == 1);
    assert(l2.getDato(0) == 1);

    l1.insertar(0, 2);

    assert(l1.getDato(0) == 2);
    assert(l2.getDato(0) == 1);
  }

  {
    Lista<int> l1;
    l1.insertar(0, 1);
    l1.insertar(1, 2);

    assert(l1.getTamanio() == 2);
    assert(l1.getDato(1) == 2);
  }

  {
    try {
      Lista<int> l1;
      l1.insertar(10, 2);
      assert(false);
    } catch (const std::invalid_argument &error) {
      assert(std::string(error.what()) ==
             "la posicion debe ser menor que el tamanio");
    }
  }

  {
    Lista<int> l1;
    l1.insertarUltimo(1);
    assert(l1.getDato(l1.getTamanio() - 1) == 1);
    l1.insertarUltimo(2);
    assert(l1.getDato(l1.getTamanio() - 1) == 2);
  }

  {
    try {
      Lista<int> l1;
      l1.remover(0);
      assert(false);
    } catch (const std::invalid_argument &error) {
      assert(std::string(error.what()) ==
             "no se pueden remover elementos de una lista vacia");
    }
  }

  std::cout << "Test Lista OK\n";
}

void test_Lista_2() {
  {
    try {
      Lista<int> l1;
      l1.insertarUltimo(1);
      l1.remover(1);
      assert(false);
    } catch (const std::invalid_argument &error) {
      assert(std::string(error.what()) ==
             "la posicion debe ser menor que el tamanio");
    }
  }

  {
    Lista<int> l1;
    l1.insertarUltimo(1);
    l1.remover(0);
    assert(l1.esVacia() == true);
  }

  std::cout << "Test Lista_2 OK\n";
}

int main() {

  test_contarVocalV2();
  test_Lista();
  test_Lista_2();

  std::cout << "Ejercicio 4 - U2 TP2 Listas" << std::endl;
  std::cout << "---------------------------" << std::endl;

  // ESCRITO POR MI
  //  Lista<std::string> lista1;
  //  std::string palabra;

  Lista<char> lista1;
  std::string palabra;
  char vocal;

  std::cout << "Escriba una palabra: \n";
  std::getline(std::cin, palabra);
  // std::cout<<"-----------\n";
  // std::cout<<palabra<<std::endl;

  // inserto palabra separa letra por letra
  for (unsigned long i = 0; i < palabra.length(); i++) {
    char letra = palabra[i];
    lista1.insertarUltimo(letra);
  }

  if (lista1.esVacia()) {
    std::cout << "Lista vacia" << std::endl;
    return 0;
  }

  std::cout << "Ingrese la vocal que desea contar: " << std::endl;
  std::cin >> vocal;

  if (!esVocal(vocal)) {
    std::cout << "La letra ingresada no es vocal" << std::endl;
    return 0;
  }

  std::cout << "La vocal ingresa es " << vocal << std::endl;
  std::cout << "La cantidad de veces que aparece la vocal es: "
            << contarVocal(lista1, vocal) << "\n";

  std::cout << "La Lista es: " << std::endl;
  lista1.print();

  return 0;
}
