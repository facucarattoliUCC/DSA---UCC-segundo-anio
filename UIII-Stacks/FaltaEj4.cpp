/*DUDAS::
1) En la funcion sumaPila si yo quisiera sobrecargar este operador "acumulador += pil.push(aux.pop());"
    como podria hacerlo?
2) En este ejemplo del codigo de los "profes" porque vuelve a restaurar la pila luego de sumar haciendo
    ""while (!pilaAux.esVacia()) { pila.push(pilaAux.pop());}"" si nunca uso la pilaAux para desapilar
    cuando hace la sumaTotal ? osea cuando hace sumaTotal += pila.pop(); donde se guardan esos valores?

    // Si "n" no se encuentra, sumar los elementos restantes
    if (!encontrado) {
    // Al reponer los elementos en la pila, la pilaAux estará vacía y no podemos sumarla directamente
    // Desapilamos de nuevo para sumar
    int sumaTotal = 0;
    while (!pila.esVacia()) {
        sumaTotal += pila.pop();
    }
    // Restaurar la pila original después de sumar
    while (!pilaAux.esVacia()) {
        pila.push(pilaAux.pop());
    }
    return sumaTotal;
    }
3)

 */

#include <iostream>
#include "Pila.h"

int sumaPila (Pila<int>& pil, int n) {
    Pila<int>aux;
    int valor, acumulador = 0;
    // while (!pil.esVacia()) {
    //     int valor = pil.pop();
    //     aux.push(valor);
    //
    //     if (valor == n ) {
    //         int acumulador = 0;
    //         acumulador += valor;
    //
    //     }
    // }

    while (!pil.esVacia()) {
        valor = pil.pop();
        if (valor == n) {
            break;
        }
        aux.push(valor);

    }

    while (!aux.esVacia()) {
        valor = aux.pop();
        acumulador += valor;
        pil.push(valor);
    }

    return acumulador;

}

void printPila (Pila<int>& pil1) {
    Pila<int>aux;

    while (!pil1.esVacia()) {
        int valor = pil1.pop();
        std::cout << valor << "->";
        aux.push(valor);
    }

    while (!aux.esVacia()) {
        pil1.push(aux.pop());
    }
}


int main() {

    std::cout<<"U3: PILAS/STACKS -- Ejercicio 4\n";
    std::cout<<"-------------------------------\n";

    Pila <int> pila;
    int nros, n;

    do {
        std::cout<<"Ingrese la cantidad de numeros enteros que desee\n";
        std::cout<<"PARA CONTINUAR LA EJECUCION DEL PROGRAMA INGRESE UN NUMERO NEGATIVO .\n";
        std::cin>>nros;
        if (nros >= 0) {
            pila.push(nros);
        }
    } while (nros >= 0);

    printPila(pila);
    std::cout<<"\n";

    std::cout<<"Ingrese un numero entero. Este sera para calcular la suma\n";
    std::cin>>n;
    std::cout<<"La suma es "<<sumaPila(pila,n)<<std::endl;

    return 0;
}
