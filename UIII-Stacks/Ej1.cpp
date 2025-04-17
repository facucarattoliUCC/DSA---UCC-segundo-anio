/*DUDAS::
1) linea 43 a 50:: dejo comentado el primer codigo que intente escribir. En que fallo mi logica?
2) linea 16:: cuando creo la funcion guardaLetra y hago pil.push() . Deberia crear una variable
   para almacenar cada letra o las letras se guardan automaticamente en la pila?
3) porque solo me imprime una letra? como hago para obtener toda la palabra y no solo el caracter?
4) como hago para leer la palabra completa? Si declara palabra como string no se como obtener cada
   caracter de la palabra para hacer el .push()
5)
 */

#include "Pila.h"
#include <iostream>
#include <cassert>

void guardarLetra (Pila <char>& pil, char& letra) {
 std::cin.get(letra);

 while (letra != '\n') {
  pil.push(letra);
 }

}

char invertirPalabra (Pila <char>& pil) {

 assert(!pil.esVacia()); //verifico si la pila no esta vacia
 char invertida;

 do {
  invertida = pil.pop();
 } while(pil.esVacia() == false);

 return invertida;

}



int main() {

 std::cout<<"U3: PILAS/STACKS -- Ejercicio 1\n";
 std::cout<<"-------------------------------\n";


 Pila<char> pila1;
 char palabra;

 std::cout<<"Ingrese una palabra: ";
 std::cin>>palabra;
 std::cout<<"La palabra es "<<palabra<<std::endl;

 // //meto la palabra en la pila
 // pila1.push(palabra);

 // //invierto palabra
 // char invertida;
 // invertida = pila1.pop();

 //std::cout<<"La palabra invertida es "<<invertida<<std::endl;

 guardarLetra(pila1, palabra);
 char palabraInvertida = invertirPalabra(pila1);

 std::cout<< "La palabra invertida es "<<palabraInvertida<<std::endl;
 return 0;

}