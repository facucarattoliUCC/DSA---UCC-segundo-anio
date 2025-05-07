/*DUDAS
1) cando el numero esta en la cola me hace la suma de todos los valores de la cola menos de ese numero n
   cuando en realidad deberia sumarme hasta el numero n sin incluirlo
2) En el condicional if (encontrado) cuando n esta en la cola para detener la suma cuando valor == n si utilizo un
   break para corta la suma se saldria del ciclo while y perderia informacion, es decir dejaria de encolar los valores

 */

#include <iostream>
#include "Cola.h"
#include <cassert>

void sumaEnteros (Cola<int>& col1, int n) {
    Cola<int> aux1;
    int valor, acumu = 0;
    bool encontrado = false;

    while (!col1.esVacia()) {
        valor = col1.desencolar();

        if (valor == n) {
            encontrado = true; // bandera para saber si el numero n esta o no en la cola
        }

        aux1.encolar(valor);
    }

    //si n no esta en cola sumo todos los valores.
    if (!encontrado) {
        while (!aux1.esVacia()) {
            valor = aux1.desencolar();
            acumu += valor;
            col1.encolar(valor);
        }
        std::cout << "El numero "<<n<<" no estaba en cola. \n";
        std::cout<<"Por lo tanto la suma es "<<acumu << std::endl;
    }

    //si n esta en cola sumo los valores hasta n sin incluirlo.
    if (encontrado) {

        while (!aux1.esVacia()) {
            valor = aux1.desencolar();
            encontrado = false; //controlo si n == valor entonces no lo sumo solo lo encolo.

            if (valor == n) {
                col1.encolar(valor);
                //encontrado = true;
                break;
            } //else if (valor != n && encontrado == false) {
            else {
                acumu += valor;
                col1.encolar(valor);
            }
        }

        std::cout<<"La suma es "<<acumu << std::endl;
    }

    while (!aux1.esVacia()) {
        col1.encolar(aux1.desencolar());
    }
}

void printCola (Cola<int>& col2) {
    Cola<int> aux2;

    while (!col2.esVacia()) {
       int valor = col2.desencolar();
        std::cout << valor << " ";
        aux2.encolar(valor);
    }

    std::cout << std::endl;

    while (!aux2.esVacia()) {
        col2.encolar(aux2.desencolar());
    }

}

int main () {
    std::cout<<"UNIDAD IV QUEUE/COLA ::GUIA TP 4 - EJERCICIO 2::\n";
    std::cout<<"------------------------------------------------\n";

    Cola <int> cola;
    int nros, n;

    do {
        std::cout<<"Ingrese numeros enteros a la cola (Presion 0 para continuar)\n";
        std::cin>>nros;
        if (nros !=0 ) {
            cola.encolar(nros);
        }
    } while (nros != 0);

    std::cout<< "La cola original es: \n";
    printCola(cola);
    std::cout<<"**************************************\n";

    std::cout<<"Ingrese un numero entero para calcular la suma\n";
    std::cin>>n;
    sumaEnteros(cola, n);

    std::cout<<"La cola es \n";
    printCola(cola);

    return 0;
}
