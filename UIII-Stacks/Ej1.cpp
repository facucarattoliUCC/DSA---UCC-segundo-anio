/*DUDAS::
1) linea 43 a 50:: dejo comentado el primer codigo que intente escribir. En que
fallo mi logica?

2) linea 16:: cuando creo la funcion guardaLetra y hago
pil.push() . Deberia crear una variable para almacenar cada letra o las letras
se guardan automaticamente en la pila?

3) porque solo me imprime una letra? como
hago para obtener toda la palabra y no solo el caracter?

4) como hago para leer
la palabra completa? Si declara palabra como string no se como obtener cada
   caracter de la palabra para hacer el .push()
5)
 */

#include "Pila.h"
#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>

void guardarLetra(Pila<char> &pil, char &letra) {
  std::cin.get(letra);

  while (letra != '\n') {
    pil.push(letra);
  }
}

char invertirPalabra(Pila<char> &pil) {

  assert(!pil.esVacia()); // verifico si la pila no esta vacia
  char invertida;

  do {
    invertida = pil.pop();
  } while (pil.esVacia() == false);

  return invertida;
}

std::string invertirPalabraV2(std::string palabra) {
  // 1234
  // convertir string a char
  // push 1 push 2 push 3 push 4
  // pop 4  pop  3 pop  2 pop  1
  // convertir char a string

  Pila<char> pila;

  for (std::size_t i = 0; i < palabra.size(); i++) {
    pila.push(palabra[i]);
  }

  std::string palabraInvertida = "";

  while (!pila.esVacia()) {
    palabraInvertida += pila.pop();
  }

  return palabraInvertida;
}

void test_invertirPalabraV2() {
  assert(invertirPalabraV2("123") == "321");
  assert(invertirPalabraV2("") == "");

  std::cout << "Test invertirPalabraV2 OK\n";
}

int main() {

  test_invertirPalabraV2();

  std::cout << "U3: PILAS/STACKS -- Ejercicio 1\n";
  std::cout << "-------------------------------\n";

  Pila<char> pila1;
  std::string palabra;

  std::cout << "Ingrese una palabra: ";
  std::cin >> palabra;
  std::cout << "La palabra es: " << palabra << std::endl;

  std::string palabraInvertida = invertirPalabraV2(palabra);

  std::cout << "La palabra invertida es: " << palabraInvertida << std::endl;
  return 0;
}
