/*DUDAS::
1) podria ver si la posicion del nro es impar declarando un array o/y vector?
2) linea 27 a 34:: porque en el manejo de excepcion cuando ingreso 0 me pide el digito en ves de largarme
    el mensaje de error?
 */

#include <iostream>
#include <stdexcept>

unsigned int digitosParesPosiImpar (unsigned int nro, unsigned int tamanioNro){

    //BaseCase
    if (nro == 0) {
        throw std::invalid_argument("El numero debe ser mayor que cero");
    }
    int digitoActual = nro % 10;
    if (tamanioNro % 2 != 0 && digitoActual % 2 == 0 ) {
        return 1 + digitosParesPosiImpar( nro / 10 ,tamanioNro - 1);
    }
    return digitosParesPosiImpar( nro / 10 ,tamanioNro - 1);

}

int main() {

    std::cout<<"Ejercicio 6 - Guia 1: Recursividad\n";
    std::cout<<"-----------------------------------\n";

    unsigned int nro, digitos;
    try {
        std::cout<<"Ingrese un numero entero positivo: \n";
        std::cin >> nro;
    } catch (const std::invalid_argument& e) {
        std::cout<<"Error: "<<e.what()<<"\n";
    }
    std::cout<<"Ingrese la cantidad de digitos del nro: \n";
    std::cin >> digitos;


    unsigned int resultado = digitosParesPosiImpar(nro,digitos);
    std::cout<<"El resultado es: "<<resultado;

    return 0;
}