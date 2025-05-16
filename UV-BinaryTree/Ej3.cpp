/*DUDAS
1)
 */

#include <iostream>
#include "Arbol/ArbolBinario.h"

int main () {

    std::cout << "GUIA TP 5a - ARBOLES BINARIOS - EJERCICIO 3\n";
    std::cout << "-------------------------------------------\n";

    ArbolBinario<int> arbol;

    arbol.put(500);
    arbol.put(250);
    arbol.put(750);
    arbol.put(100);
    arbol.put(300);
    arbol.put(600);
    arbol.put(800);

    // std::cout<<"Arbol mostrado inOrder\n";
    // arbol.inorder();
    //
    // std::cout<<"Arbol mostrado postOrder\n";
    // arbol.postorder();
    //
    // std::cout<<"Arbol mostrado preOrder\n";
    // arbol.preorder();

    //arbol.print();

    arbol.remove(250);
    std::cout<<"Arbol modificado inOrder\n";
    arbol.inorder();

    std::cout<<"Arbol modificado postOrder\n";
    arbol.postorder();

    std::cout<<"Arbol modificado preOrder\n";
    arbol.preorder();

    arbol.print();

    return 0;
}
