/* DUDAS:
1) funcion mostrarPila():: al no pasarle el parametro pila por referencia es necesario que vuelva los valores
   de la pila aux a la pila original? --> me costo muchisimo escribir ese codigo imaginarme la logica de como hacerlo
2) cuando uso .pop() donde quedan esos valores? ya que si creo una variable pe de tipo int no puedo asignarle pi.pop()
   porque no son del mismo... pi.pop() representa un valor del tipo de dato que sea que guarde la pila?
3) como podria hacer para imprimir un mensaje en caso que el valor ingresado no se encuentre en la pila?
 */

#include "Pila.h"
#include <iostream>

void Reemplazar (Pila<int>& pi, int viejo1, int nuevo1){

 // while (!pi.esVacia()) {
 //  if (viejo1 == pi.pop()) {
 //   pi.pop();
 //   pi.push(nuevo1);
 //   Pila<int> nuevaPila = pi;
 //  }
 //}
 Pila<int> aux;

 while (!pi.esVacia()) {
  //aux.push(pi.pop());
  int valor = pi.pop();
  if (valor == viejo1) {
   aux.push(nuevo1);
  } else {
   aux.push(valor);
  }
 }

 while (!aux.esVacia()) {
  pi.push(aux.pop());
 }
}

void mostrarPila (Pila<int>& pil) {
 Pila<int> aux;

 while (pil.esVacia() != true) {
  int valor = pil.pop();
  std::cout<<valor<<"\n";
  aux.push(valor);
 }

 while (!aux.esVacia()) {
  pil.push(aux.pop());
 }
}

int main() {

 std::cout<<"U3: PILAS/STACKS -- Ejercicio 2\n";
 std::cout<<"-------------------------------\n";

 Pila<int> pila1;
 int viejo, nuevo;

 pila1.push(9);
 pila1.push(2);
 pila1.push(3);
 pila1.push(9);
 pila1.push(7);
 pila1.push(9);

 std::cout<<"La pila original es \n";
 mostrarPila(pila1);
 //mostrarPila(pila1);

 std::cout<<"Ingrese nro entero que desea eliminar de pila: \n";
 std::cin>>viejo;
 std::cout<<"Ingrese nro entero que reemplazara al eliminado: \n";
 std::cin>>nuevo;
 Reemplazar(pila1, viejo, nuevo);

 std::cout<<"Ahora pila es \n";
 mostrarPila(pila1);




 return 0;
}