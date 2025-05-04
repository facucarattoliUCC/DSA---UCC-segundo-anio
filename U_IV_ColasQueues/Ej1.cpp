/*DUDAS
1) no se como manejar el ciclo para cuando las colas son de diferentes tamanios, es decir como determino si una cola
   es mas chica que la otra?

 */

#include <iostream>
#include "Cola.h"

bool sonIguales (Cola <char>& col1, Cola <char>& col2) {
    bool iguales = false;

    do {
        //controlo tamanio de colas. Si alguna cola esta vacia y otra no termina el ciclo.
        if (col1.esVacia() || col2.esVacia()) {

            if (col1.esVacia()) {
                std::cout<<"Cola 1 no tiene mas elementos\n";
            } else {
                std::cout<<"Cola 2 no tiene mas elementos\n";
            }

            return iguales;
        }

        char caracter = col1.desencolar();
        char caracter2 = col2.desencolar();

        //controlo que elementos sean iguales. Con que uno elemento sea diferente return false
        if ( caracter != caracter2 ) {
            iguales = false;
            return iguales;
        } else {
            iguales = true;
        }

    } while (!col1.esVacia() && !col2.esVacia());

    return iguales;
}

int main () {
    std::cout<<"UNIDAD IV QUEUE/COLA ::GUIA TP 4 - EJERCICIO 1::\n";
    std::cout<<"------------------------------------------------\n";

    Cola <char> cola1, cola2;
    char c, c1;

    std::cout<<"Ingrese caracteres para la Queue1: (presione 0 para salir)\n";
    do {
        std::cin>>c;
        if (c == '0' ) {
            break;
        }
        cola1.encolar(c);
    } while ( c != '0');

    std::cout<<"Ingrese caracteres para la Queue2: (presione 0 para salir)\n";
    do {
        std::cin>>c1;
        if (c1 == '0' ) {
            break;
        }
        cola2.encolar(c1);
    } while ( c1 != 0);

    if (!sonIguales(cola1, cola2)) {
        std::cout<<"Las colas no son iguales\n";
    } else {
        std::cout<<"Las colas son iguales\n";
    }

    return 0;
}
