/*DUDAS
1)
 */

#include <iostream>
#include "Cola.h"
#include "Pila.h"
#include <stdexcept>
#include <cassert>

void ordenarColaPila (Cola <int>& col1, Pila <int>& pil1) {
    Cola <int> auxCola1;

    if (col1.esVacia()) {
        throw std::invalid_argument("Cola vacia");
    }

    while (!col1.esVacia()) {
        int valor = col1.desencolar();
        if (valor % 2 == 0) {
            auxCola1.encolar(valor);
        } else {
            pil1.push(valor);
        }
    }

    while (!auxCola1.esVacia()) {
        col1.encolar(auxCola1.desencolar());
    }
}

void printCola (Cola <int>& col2) {
    Cola <int> auxCola2;

    while (!col2.esVacia()) {
        int valorCola = col2.desencolar();
        std::cout << valorCola << " ";
        auxCola2.encolar(valorCola);
    }

    std::cout << std::endl;

    while (!auxCola2.esVacia()) {
        col2.encolar(auxCola2.desencolar());
    }

}

void printPila (Pila <int>& pil2) {
    Pila <int> auxPila2;

    while (!pil2.esVacia()) {
        int datoPila = pil2.pop();
        std::cout << datoPila << " ";
        auxPila2.push(datoPila);
    }

    std::cout << std::endl;

    while (!auxPila2.esVacia()) {
        pil2.push(auxPila2.pop());
    }

}


int main () {
    std::cout<<"UNIDAD IV QUEUE/COLA ::GUIA TP 4 - EJERCICIO 5::\n";
    std::cout<<"------------------------------------------------\n";

    Cola <int> cola;
    Pila<int> pila;
    int nros;

    try {
        do {
            std::cout<<"Ingrese numeros enteros a la cola (PRESIONE 0 PARA SALIR)\n";
            std::cin>>nros;
            if (nros != 0) {
                cola.encolar(nros);
            }
        } while (nros !=0 );

        std::cout<<"La cola original es \n";
        printCola(cola);

    } catch (std::invalid_argument& e) {
        std::cout<<"ERROR: "<<e.what()<<"\n";
    }

    ordenarColaPila(cola, pila);

    std::cout<<"La cola luego de ordenarla con numeros pares es \n";
    printCola(cola);

    std::cout<<"La pila, luego de ordenar la cola, es \n";
    printPila(pila);




    return 0;
}
