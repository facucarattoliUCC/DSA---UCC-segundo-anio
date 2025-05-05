/*DUDAS
1) PORQUE ME FALLA EL ASSERT EN LA FUNCION eliminarOcurrencia ?
2) eliminarOcurrencia no me elimina el nro cuando se repite mas de una vez!
3)
 */

#include <iostream>
#include "Cola.h"
#include <cassert>

void eliminarOcurrencia (Cola<int>& col1, int n) {
    Cola<int> aux;
    //assert(col1.esVacia());
    int contador = 0;

    while (!col1.esVacia()) {
        int valor = col1.desencolar();
        if (valor == n ) {
            contador++;
        }
        aux.encolar(valor);
    }

    if (contador == 0) {
        std::cout<<"El numero no esta en la cola\n";
        while (!aux.esVacia()) {
            col1.encolar(aux.desencolar());
        }
    }

    if (contador == 1) {
        while (!aux.esVacia()) {
            int valor = aux.desencolar();
            if (valor != n) {
                col1.encolar(valor);
            }
        }
    }

    if (contador >= 2 ) {
        bool encontrado;
        while (!aux.esVacia()) {
            int valor = aux.desencolar();
            if (valor == n && !encontrado ) {
                encontrado = true;
                col1.encolar(valor);
            }  else {
                col1.encolar(valor);
            }
        }
    }

}

void printCola (Cola<int>& col2) {
    Cola<int> aux2;

    while (!col2.esVacia()) {
        int valor = col2.desencolar();
        std::cout<<valor<<" ";
        aux2.encolar(valor);
    }

    std::cout<<"\n";

    while (!aux2.esVacia()) {
        col2.encolar(aux2.desencolar());
    }
}


int main () {
    std::cout<<"UNIDAD IV QUEUE/COLA ::GUIA TP 4 - EJERCICIO 3::\n";
    std::cout<<"------------------------------------------------\n";

    Cola <int> cola;
    int nro, n;

    do {
        std::cout<<"Ingrese numeros enteros a la cola. (Presione 0 para salir)\n";
        std::cin>>nro;
        if (nro > 0 ) {
            cola.encolar(nro);
        }
    }while ( nro > 0 );

    std::cout<<"La cola es: \n";
    printCola(cola);

    std::cout<<"Ingrese un numero para eliminar de la cola.\n";
    std::cin>>n;
    eliminarOcurrencia(cola, n);

    std::cout<<"La cola modificada es: \n";
    printCola(cola);

    return 0;
}
