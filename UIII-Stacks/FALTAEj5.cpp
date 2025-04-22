/* DUDAS::

 */

#include <iostream>
#include "Pila.h"
#include <cassert>

void printPila (Pila <int>& pil1) {
    Pila<int> aux1;

    std::cout<<"Pila original\n";
    while (!pil1.esVacia()) {
        int valor = pil1.pop();
        std::cout << valor << "->" ;
        aux1.push(valor);
    }
    std::cout << std::endl;

    std::cout <<"Pila reestablecida\n";
    while (!aux1.esVacia()) {
        int valor = aux1.pop();
        std::cout << valor << "->" ;
        pil1.push(valor);
    }
}

//creo una funcion que devuelve una pila
Pila<int> sumaEnteros(Pila<int>& pil2, int nro ) {

    Pila<int> pilaSuma, aux2, auxSuma;
    assert(!pil2.esVacia());

    while (!pil2.esVacia()) {
        int valor = pil2.pop();
        aux2.push(valor);
        auxSuma.push(valor+nro);
    }
    //ubico los datos, de la pila original, en su posicion correspondiente
    while (!aux2.esVacia()) {
        int valor = aux2.pop();
        pil2.push(valor);
    }

    //ubico los valores en su posicion original
    while (!auxSuma.esVacia()) {
        int valorSumado = auxSuma.pop();
        pilaSuma.push(valorSumado);
        return pilaSuma;
    }

};

int main() {
     std::cout<<"U3: PILAS/STACKS -- Ejercicio 5\n";
     std::cout<<"-------------------------------\n";

    Pila <int> pila;
    int n;

    pila.push(4); //ultimo de la lista. Linealmente es el primer dato que entro a la pila
    pila.push(3);
    pila.push(6);
    pila.push(9);
    pila.push(8); //tope de la lista. LIFO {last in , first out}. Linealmente es el ultimo dato que entro a la pila

    printPila(pila);
    std::cout<<std::endl;

    std::cout<<"Ingrese un numero entero\n";
    std::cin>>n;

    sumaEnteros(pila, n);
    printPila(pila);

     return 0;
}
