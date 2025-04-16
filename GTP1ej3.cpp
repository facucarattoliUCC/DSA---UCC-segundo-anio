/*DUDAS
linea 12 :: cuando retorno la funcion recursiva, donde/como guarda el valor calculado?
 */
#include <iostream>

unsigned int invertirNumero (unsigned int n, int invertido=0) {

    if (n == 0) {
        //return 0; SI RETORNO CERO MI RESULTADO SIEMPRE SERA CERO EN VEZ DEL NUMERO INVERTIDO
        return invertido;
    }

    return invertirNumero( n/10, invertido * 10 + n % 10 );

}

int main () {
    std::cout<<"Ejercicio 3 - Guia 1: Recursividad\n";
    std::cout<<"-----------------------------------\n";

    int nro, invertido = 0 ;

    std::cout << "Ingrese el numero que desea invertir: \n";
    std::cin >> nro;

    unsigned int nroInvertido = invertirNumero(nro);

    std::cout << "El numero a invertir es: "<< nro << std::endl;
    std::cout << "El numero invertido es: "<< nroInvertido << std::endl;

    return 0;
}
