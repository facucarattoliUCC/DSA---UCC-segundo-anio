#include <iostream>

bool digitoSiNo (unsigned int nro, unsigned int digito){

    //BaseCase
    if (nro == 0) {
        return false;
    }
    if (nro %10 == digito) {
        return true;
    }

    //Construccion funcion recursiva
    return digitoSiNo (nro/10, digito);

}

int main () {

    std::cout<<"Ejercicio 5 - Guia 1: Recursividad\n";
    std::cout<<"-----------------------------------\n";

    unsigned int nro, digito;

    std::cout<<"Ingrese un numero entero positivo: \n";
    std::cin >> nro;

    std::cout<<"Ingrese un digito entero positivo: \n";
    std::cin >> digito;

    bool resultado = digitoSiNo(nro, digito);

    if (!resultado ) {
        std::cout<<"Numero ingresado: " <<nro<<std::endl;
        std::cout<<"Digito ingresado: " <<digito<<std::endl;
        std::cout<<"El resultado es: false\n";
        //return false;
        //std::cout<<"False\n";
    } else {
        std::cout<<"Numero ingresado: " <<nro<<std::endl;
        std::cout<<"Digito ingresado: " <<digito<<std::endl;
        std::cout<<"El resultado es: True\n";
        //return 'true';
    }

    return 0;
}
