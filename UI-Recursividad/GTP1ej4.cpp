/*DUDAS:
1) Linea 38 a 46:: esta bien manejado el error? la asignacion de la f calculoMayor y la muestra de su resultado
deberia ir en el cuerpo del catch?
2) como le asigno elementos a mi vector?
3) Cuando ejecuto el programa siempre me imprime cero.
 */

#include <iostream>
#include <vector>
#include <stdexcept>

int calculoMayor (unsigned int tamanio,std::vector<int> vector){

    //CasoBase..
    //si el taminio es 0 significa que no hay elemento entonces que retorne 0...
    //si el taminio es 1 signicia que hay un elemento entonces que me retorne ese elemento accediendo al vector en la unica posicion que tiene
    if (tamanio == 0) {
        throw std::invalid_argument("Tamanio del vector debe ser mayor que 0");
    }

    //Si el vector tiene un elemento entonces que retorno al vector en la posicion inicial
    if (tamanio == 1) {
        return vector[0];
    }

    //Construccion recursividad
    int maximo = calculoMayor (tamanio-1,vector);
    return (maximo > vector[tamanio-1] ? maximo : vector[tamanio-1]);

    //De esta manera estoy haciendo llamado a f calculoMayor() dos veces.
    //Una llamada "int maximo = calculoMayor (tamanio-1,vector)". Otra llamada "if (maximo > calculoMayor (tamanio-1,vector)"
    //Esto hace que la recursividaad se ejecute dos veces innecesariamente
    // if (maximo > calculoMayor (tamanio-1,vector)){
    //     return maximo;
    // }
    // return vector[tamanio-1];

}

int main() {

    std::cout<<"Ejercicio 4 - Guia 1: Recursividad\n";
    std::cout<<"-----------------------------------\n";

    int tama, elemMayor, i;
    try {
        std::cout<<"Ingrese el tamanio del vector: \n";
        std::cin>> tama;

    } catch (const std::invalid_argument& e) {
        std::cout<<"Error: "<<e.what()<<"\n";
    }

    std::vector<int>miVector(tama);

    for (i = 0; i < tama; ++i) {
         miVector[i];
    }
        elemMayor = calculoMayor (tama, miVector);

    std::cout<<"El elemento mayor es: "<< elemMayor;

    return 0;
}