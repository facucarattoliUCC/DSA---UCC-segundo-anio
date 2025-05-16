/*DUDAS
1)
 */

#include <iostream>
#include "Arbol/ArbolBinario.h"

int main () {

    std::cout << "GUIA TP 5a - ARBOLES BINARIOS - EJERCICIO 4\n";
    std::cout << "-------------------------------------------\n";

    ArbolBinario<int> arbol;

    arbol.put(15);
    arbol.put(10);
    arbol.put(20);
    arbol.put(5);
    arbol.put(12);
    arbol.put(18);
    arbol.put(25);

    //  std::cout<<"Arbol mostrado inOrder\n";
    //  arbol.inorder();
    //
    //  std::cout<<"Arbol mostrado postOrder\n";
    //  arbol.postorder();
    //
    //  std::cout<<"Arbol mostrado preOrder\n";
    //  arbol.preorder();
    //
    // arbol.print();

    arbol.remove(10);
    arbol.remove(20);
    arbol.put(13);
    arbol.put(4);
    arbol.put(6);
    std::cout<<"Arbol modificado inOrder\n";
    arbol.inorder();

    std::cout<<"Arbol modificado postOrder\n";
    arbol.postorder();

    std::cout<<"Arbol modificado preOrder\n";
    arbol.preorder();

    arbol.print();

    return 0;
}

