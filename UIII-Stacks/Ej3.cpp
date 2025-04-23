/*DUDAS::
1) me costo mucho aplicar la logica para cuando el numero ya fue encontrado mas
de una vez dejar la primera ocurrencia y eliminar las demas... Lo mismo me
sucedio cuando quise eliminar


2) Deberia crear dos funciones distintas? Una para contar las veces que aparece
el numero y otra para eliminarlo? No

3) linea 64 a 75:: Cuando imprimo la pila con la funcion printPila le aplico -->
para indicar el siguiente dato la cuestion es que cuando me muestra el ultimo
dato tambien me muestra --> apuntando a la nada. como puedo hacer para que
cuando aparece el ultimo dato no se imprima "-->"?

4) Me hace ruido como la funcion printPila imprime los valores. Ya que cuando
hago pil1.pop() e imprimo ese valor deberia aparecerme primero en pantalla. En
este caso seria el 2 --> 3 --> 8 --> etc... Pero por pantalla me sale al reves.
Primero se imprime el ultimo de la pila!

5) Cuando vuelvo a imprimir la pila
despues de eliminar el numero :: no me imprime nada si el nro no esta en la pila
; me imprime solamente el numero si este aparece mas de una vez.. EL unico caso
que funciona bien es cuando el numero aparece solo una vez

6) podria haber
manejado la logica de contar cuantas veces aparece el numero y eliminarlo en un
solo bloque if?

7) linea 50 a 62 :: no puede eliminar el numero cuando se repite
mas de una vez y dejar solo la primer ocurrencia
 */

#include "Pila.h"
#include <cassert>
#include <iostream>

// pila.pop() != numero
//   -> aux.push()
// pila.push(aux.pop())

void RemoverV2(Pila<int> &pila, int numero) {
  Pila<int> aux;

  while (!pila.esVacia()) {
    int dato = pila.pop();
    if (dato != numero) {
      aux.push(dato);
    }
  }

  while (!aux.esVacia()) {
    pila.push(aux.pop());
  }
}

void Remover(Pila<int> &pil, int numero) {
  Pila<int> aux;
  int valor, contador = 0;
  while (!pil.esVacia()) {
    valor = pil.pop();
    if (valor == numero) {
      contador++;
      aux.push(valor);
    } else {
      aux.push(valor);
    }
  }
  if (contador == 0) {
    std::cout << "El valor no pertence a la pila" << std::endl;
    // throw "El valor no pertence a la pila";
    while (!aux.esVacia()) {
      pil.push(aux.pop());
    }
  }

  if (contador == 1) {
    while (!aux.esVacia()) {
      valor = aux.pop();
      if (valor != numero) {
        pil.push(valor);
      }
    }
  }

  if (contador >= 2) {
    bool encontrado = false;
    while (!aux.esVacia()) {
      valor = aux.pop();
      if (valor == numero && !encontrado) {
        pil.push(valor);
        encontrado = true;
      } else {
        pil.push(valor);
      }
    }
  }
}

// Esta función recibe como parámetro una pila pil1 del tipo Pila<int>, pasada
// por valor (es decir, se hace una copia de la pila original usando el
// constructor por copia).
void printPila(Pila<int> pil1) {
  while (!pil1.esVacia()) {
    std::cout << pil1.pop() << " --> ";
  }
  std::cout << "nullptr\n";
}

// Esta función recibe como parámetro una pila pil1 del tipo Pila<int>, pasada
// por referencia (es decir, NO se hace una copia de la pila original).
void printPilaRecursivo(Pila<int> &pil1) {
  if (pil1.esVacia()) {
    std::cout << "nullptr\n";
    return;
  }

  int dato = pil1.pop();
  std::cout << dato << " --> ";

  printPila(pil1);

  pil1.push(dato);
}

void test_RemoverV2() {

  {
    Pila<int> p;
    RemoverV2(p, 5);
    assert(p.esVacia() == true);
  }

  {
    Pila<int> p;
    p.push(5);
    RemoverV2(p, 5);
    assert(p.esVacia() == true);
  }

  {
    Pila<int> p;
    p.push(1);
    RemoverV2(p, 5);
    assert(p.esVacia() == false);
    assert(p.pop() == 1);
    assert(p.esVacia() == true);
  }

  {
    Pila<int> p;
    p.push(1);
    p.push(2);
    p.push(2);
    p.push(1);
    RemoverV2(p, 2);
    assert(p.esVacia() == false);
    assert(p.pop() == 1);
    assert(p.pop() == 1);
    assert(p.esVacia() == true);
  }

  std::cout << "Test RemoverV2 OK\n";
}

// Pila{1,2,3}
// pop 1 Pila{2,3}
//   1 == numero    test_RemoverV3(Pila{2,3})
void RemoverV3(Pila<int> &pila, int numero) {
  if (pila.esVacia()) {
    return;
  }

  int dato = pila.pop();

  RemoverV3(pila, numero);

  if (dato != numero) {
    pila.push(dato);
  }
}

void test_RemoverV3() {

  {
    Pila<int> p;
    RemoverV3(p, 5);
    assert(p.esVacia() == true);
  }

  {
    Pila<int> p;
    p.push(5);
    RemoverV3(p, 5);
    assert(p.esVacia() == true);
  }

  {
    Pila<int> p;
    p.push(1);
    RemoverV3(p, 5);
    assert(p.esVacia() == false);
    assert(p.pop() == 1);
    assert(p.esVacia() == true);
  }

  {
    Pila<int> p;
    p.push(1);
    p.push(2);
    p.push(2);
    p.push(1);
    RemoverV3(p, 2);
    assert(p.esVacia() == false);
    assert(p.pop() == 1);
    assert(p.pop() == 1);
    assert(p.esVacia() == true);
  }

  std::cout << "Test RemoverV3 OK\n";
}

int main() {

  test_RemoverV2();
  test_RemoverV3();

  std::cout << "U3: PILAS/STACKS -- Ejercicio 3\n";
  std::cout << "-------------------------------\n";

  Pila<int> pila;
  int nro;

  pila.push(2);
  pila.push(3);
  pila.push(8);
  pila.push(4);
  pila.push(3);
  pila.push(11);

  std::cout << "La pila contiene los siguientes datos\n";
  printPila(pila);
  printPilaRecursivo(pila);
  std::cout << "\n";

  std::cout << "Ingrese el numero que desea eliminar\n";
  std::cin >> nro;
  RemoverV3(pila, nro);

  std::cout << "Pila modificada\n";
  printPila(pila);
  printPilaRecursivo(pila);

  return 0;
}
