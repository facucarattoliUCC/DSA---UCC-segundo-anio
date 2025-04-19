/*DUDAS::
1) me costo mucho aplicar la logica para cuando el numero ya fue encontrado mas de una vez dejar la primera
   ocurrencia y eliminar las demas... Lo mismo me sucedio cuando quise eliminar
2) Deberia crear dos funciones distintas? Una para contar las veces que aparece el numero y otra para eliminarlo?
3) linea 64 a 75:: Cuando imprimo la pila con la funcion printPila le aplico --> para indicar el siguiente dato
    la cuestion es que cuando me muestra el ultimo dato tambien me muestra --> apuntando a la nada.
    como puedo hacer para que cuando aparece el ultimo dato no se imprima "-->"?
4) Me hace ruido como la funcion printPila imprime los valores. Ya que cuando hago pil1.pop() e imprimo ese valor
    deberia aparecerme primero en pantalla. En este caso seria el 2 --> 3 --> 8 --> etc... Pero por pantalla me
    sale al reves. Primero se imprime el ultimo de la pila!
5) Cuando vuelvo a imprimir la pila despues de eliminar el numero :: no me imprime nada si el nro no esta en la
    pila ; me imprime solamente el numero si este aparece mas de una vez.. EL unico caso que funciona bien es
    cuando el numero aparece solo una vez
6) podria haber manejado la logica de contar cuantas veces aparece el numero y eliminarlo en un solo bloque if?
7) linea 50 a 62 :: no puede eliminar el numero cuando se repite mas de una vez y dejar solo la primer ocurrencia
 */

#include "Pila.h"
#include <iostream>

void Remover(Pila<int>& pil, int numero) {
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
        if (contador == 0 ) {
            std::cout<<"El valor no pertence a la pila"<<std::endl;
            //throw "El valor no pertence a la pila";
            while (!aux.esVacia()) {
                pil.push(aux.pop());
            }
        }

        if (contador == 1) {
            while (!aux.esVacia()) {
                valor = aux.pop();
                if (valor != numero ) {
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

void printPila (Pila<int>& pil1) {
    Pila<int> aux;
    while (!pil1.esVacia()) {
        int valor = pil1.pop();
        aux.push(valor);
        std::cout<<valor<<" --> ";

    }
    while (!aux.esVacia()) {
        pil1.push(aux.pop());
    }
}

int main() {

    std::cout<<"U3: PILAS/STACKS -- Ejercicio 3\n";
    std::cout<<"-------------------------------\n";

    Pila<int> pila;
    int nro;

    pila.push(2);
    pila.push(3);
    pila.push(8);
    pila.push(4);
    pila.push(3);
    pila.push(11);

    std::cout<<"La pila contiene los siguientes datos\n";
    printPila(pila);
    std::cout<<"\n";

    std::cout<<"Ingrese el numero que desea eliminar\n";
    std::cin>>nro;
    Remover(pila, nro);

    std::cout<<"Pila modificada\n";
    printPila(pila);


    return 0;
}