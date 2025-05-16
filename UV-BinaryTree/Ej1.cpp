/*DUDAS
1)Al final cuando remuevo el 52 que es nodo Padre, quien tomaria el lugar como nodoPadre el 75 o el 36 ?
  hice un esquema luego de remover el 52 y puse como nuevo nodoPadre al 75.. Pero cuando recorro el arbol
  con preOrder y postOrder sale como si el nodoPadre fuese el 36
 */

#include <iostream>
#include "Arbol/ArbolBinario.h"


int main () {

 std::cout << "GUIA TP 5a - ARBOLES BINARIOS - EJERCICIO 1\n";
 std::cout << "-------------------------------------------\n";

 ArbolBinario<int> arbol;

 arbol.put(101);
 arbol.put(52);
 arbol.put(198);
 arbol.put(36);
 arbol.put(75);
 arbol.put(150);
 arbol.put(200);

 std::cout<<"Arbol mostrado inOrder\n";
 arbol.inorder();

 std::cout<<"Arbol mostrado postOrder\n";
 arbol.postorder();

 std::cout<<"Arbol mostrado preOrder\n";
 arbol.preorder();

 if (arbol.search(75)) {
  std::cout<<"El libro con id "<<arbol.search(75)<<" esta en la biblioteca\n";
 } else {
  std::cout<<"El libro con id "<<arbol.search(75)<<" no esta en la biblioteca\n";
 }

if (arbol.search(52)) {
std::cout<<"El libro con id "<< arbol.search(52)<<" fue removido de la biblioteca\n";
 arbol.remove(52);
}else {
 std::cout<<"El libro con id "<< arbol.search(52)<<" no pertenece a la biblioteca\n";
}

 std::cout<<"Arbol mostrado inOrder luego de las modificaciones\n";
 arbol.inorder();

 std::cout<<"Arbol mostrado postOrder luego de las modificaciones\n";
 arbol.postorder();

 std::cout<<"Arbol mostrado preOrder luego de las modificaciones\n";
 arbol.preorder();

 return 0;
}
