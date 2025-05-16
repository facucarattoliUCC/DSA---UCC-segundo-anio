/*DUDAS
1) misma duda que en ejercicio 1. Cuando hago el remove me cuesta ver quien toma el lugar de nodoPAdre.
   Tanto para el subarbol izquierdo como para el subarbol derecho el nodo de menor valor es el que toma el lugar de
   nodoPadre?
2) cuando ingresa el nuevo dato put (2500); despues de los remove.. Ese nuevo dato es menor que el nodo raiz va a
   la izquierda, se compara con el nodoPadre del subarbol izquierdo y es mayor , dado que 1500 es el nodoPadre .
   En este punto 2500 lo reemplaza a 1500 ? Que lugar tomaria ? porque si va a la derecha ya se encuentra el 3500
   entonces se creearia otro nivel subarbol?
3)
 */

#include <iostream>
#include "Arbol/ArbolBinario.h"

int main () {

    std::cout << "GUIA TP 5a - ARBOLES BINARIOS - EJERCICIO 2\n";
    std::cout << "-------------------------------------------\n";

    ArbolBinario<int> arbol;

    arbol.put(4001);
    arbol.put(2002);
    arbol.put(6003);
    arbol.put(1500);
    arbol.put(3500);
    arbol.put(5000);
    arbol.put(7000);

    std::cout<<"Arbol mostrado inOrder\n";
    arbol.inorder();

    std::cout<<"Arbol mostrado postOrder\n";
    arbol.postorder();

    std::cout<<"Arbol mostrado preOrder\n";
    arbol.preorder();

    arbol.remove(2002);
    arbol.remove(6003);

    std::cout<<"Arbol mostrado inOrder luego de la compra del cliente\n";
    arbol.inorder(); //1500; 3500; 4001; 5000; 7000

    std::cout<<"Arbol mostrado postOrder luego de la compra del cliente\n";
    arbol.postorder(); //3500; 1500; 5000; 7000; 4001

    std::cout<<"Arbol mostrado preOrder luego de la compra del cliente\n";
    arbol.preorder(); //4001; 1500; 3500; 7000; 5000

    arbol.put(2500);

    std::cout<<"Arbol mostrado inOrder luego ingreso nuevo producto\n";
    arbol.inorder(); //1500; 2500; 3500; 4001; 5000; 7000

    std::cout<<"Arbol mostrado postOrder luego ingreso nuevo producto\n";
    arbol.postorder(); //1500; 3500; 2500; 7000; 5000; 4001

    std::cout<<"Arbol mostrado preOrder luego ingreso nuevo producto\n";
    arbol.preorder(); //4001 ; 1500; 3500; 2500; 7000 ; 5000


    return 0;
}
