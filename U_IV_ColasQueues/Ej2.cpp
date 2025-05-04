/*DUDAS
1)
 */

#include <iostream>
#include "Cola.h"
#include <cassert>

void suprimir (Cola <int>& col1, int n) {
    Cola <int> aux1;
    assert(!col1.esVacia()); //verifico si la cola esta vacia. Si la cola es vacia true el assert arroja error

    while (!col1.esVacia()) {
        int nro = col1.desencolar();
        if (nro > n) {
        } else {
            aux1.encolar(nro);
        }
    }

    while (!aux1.esVacia()) {
        col1.encolar(aux1.desencolar());
    }
}

void printCola (Cola <int>& col2) {
    Cola <int> aux2;

    while (!col2.esVacia()) {
        int nro = col2.desencolar();
        std::cout << nro << " ";
        aux2.encolar(nro);
    }

    while (!aux2.esVacia()) {
        col2.encolar(aux2.desencolar());
    }
}


int main () {
    std::cout<<"UNIDAD IV QUEUE/COLA ::GUIA TP 4 - EJERCICIO 1::\n";
    std::cout<<"------------------------------------------------\n";

    Cola <int> cola;
    int n, numeros;

    do {
        std::cout<<"Ingrese numeros a la cola. (ingrese numero negativo o cero para continuar)\n";
        std::cin>>numeros;
        if (numeros > 0) {
            cola.encolar(numeros);
        }
    } while (numeros > 0);

    std::cout<<"La cola es \n";
    printCola(cola);
    std::cout << std::endl;

    std::cout<<"***********************************************************************\n";
    std::cout<<"Ingrese el numero. Todos lo numeros mayores al ingresado seran borrados\n";
    std::cin>>n;

    suprimir(cola, n);

    std::cout<<"La cola depurada es \n";
    printCola(cola);

    return 0;
}
