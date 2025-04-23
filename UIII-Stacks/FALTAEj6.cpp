/* DUDAS::
1) No se como manejar cuando sale la persona! Manejo cuando entra y sale de una sala con la misma funcion
   recorridoPersona. Pero en el main cuando quiero implementar la funcion se me cruzaron todas las ideas porque
   si sale o entra de una sale da lo mismo tengo que llamar a la f recorridoPersona ?

2) porque la pila me imprime solamente un valor y no me imprime todo el recorrido?
 */

#include <iostream>
#include "Pila.h"
#include <cassert>

//imprimo pila
void printPila (Pila<std::string>& pil1) {
  Pila <std::string> aux1;
  //assert (!pil1.esVacia());

  //muestro la pila. El primer lugar mostrada es el ultimo lugar que entro/salio la persona.
  //el ultimo lugar mostrado es el primer lugar que entro la persona.
  std::cout<<"Recorrido de la persona en el edificio.\n";
  while (!pil1.esVacia()) {
    std::string lugar = pil1.pop();
    std::cout << lugar << std::endl;
    aux1.push(lugar);
  }

   //reestablezco la pila como estaba originalmente
   while (!aux1.esVacia()) {
        pil1.push(aux1.pop());
   }
}

//Pila<std::string> recorridoPersona (Pila<std::string>& pil2 , int const&  lugar, std::string const& movimiento) {

void recorridoPersona (Pila<std::string>& pil2 , int const&  lugar, std::string const& movimiento) {

 //Pila <std::string> pilaRecorrido;
 //assert (!pil2.esVacia());

  if (movimiento == "in" && lugar == 1){
   pil2.push("Recepcion");
   //pilaRecorrido.push("Recepcion");
  } else if (movimiento == "in" && lugar == 2) {
   pil2.push("Lobby");
   //pilaRecorrido.push("Lobby");
  } else if (movimiento == "in" && lugar == 3) {
   pil2.push("Vestuarios");
   //pilaRecorrido.push("Vestuarios");
  } else if (movimiento == "in" && lugar == 4) {
   pil2.push("Pileta");
   //pilaRecorrido.push("Pileta");
  } else if (movimiento == "in" && lugar == 5) {
   pil2.push("Gym");
   //pilaRecorrido.push("Gym");
  } else if (movimiento == "in" && lugar == 6) {
   pil2.push("Spa");
   //pilaRecorrido.push("Spa");
  }

  if (movimiento == "out"){
   pil2.pop();
   //pilaRecorrido.push(pil2.pop());
  }

 //return pilaRecorrido;

}

int main () {

 std::cout<<"U3: PILAS/STACKS -- Ejercicio 6\n";
 std::cout<<"-------------------------------\n";

 Pila<std::string> pila;
 int lugar;
 std::string movimiento;

 do {
   std::cout<<"Sale o entra? PARA SALIR DEL EDIFICIO PRESION e\n";
   std::cout<<"In para entrar; Out para salir\n";
   std::cin>>movimiento;
   assert (movimiento == "in" || movimiento == "out" || movimiento == "e");

   //verifico si sale del edicio
    if (movimiento == "e"){
        std::cout<<"Hasta la proxima. Esperamos nuevamente su visita\n";
        break;
    }

     //pido numero de sala si la persona entra a alguna lugar
     if (movimiento == "in") {
         std::cout<<"Ingrese el numero de la sala\n";
         std::cin>>lugar;

         if (lugar > 7 || lugar <= 0) {
          std::cout<<"No existen salas con esos numeros\n";
          return 0;
          //break
         }
          recorridoPersona(pila, lugar,movimiento);
     }

      if (movimiento == "out"){
         assert (!pila.esVacia());
         // if (lugar == 7) {
         //  std::cout<<"Hasta la proxima. Esperamos nuevamente su visita\n";
         //  break;
         // }
         recorridoPersona(pila, lugar,movimiento);
      }

 } while (lugar < 7);

 printPila(pila);

 // pila.push("in Recepcion == 1");
 // pila.push("in lobby == 2");
 // pila.push("in vestuarios == 3");
 // pila.push("out vestuarios");
 // pila.push("in pileta == 4");
 // pila.push("out pileta");
 // pila.push("in gym == 5");
 // pila.push("out gym");
 // pila.push("in spa == 6 ");
 // pila.push("out spa");
 // pila.push("in vestuario");
 // pila.push("out vestuario");
 // pila.push("out edificio == 7");


 return 0;

}