/*DUDAS::
1) porque no me retorna el contador de las vocales?
2) los codigos comentados son los que intente escribir hasta que desisti. En que falle?
Cual fue la falla de mi razonamiento o logica?

 */
#include <iostream>
#include <cctype>
#include "Lista.h"

bool esVocal (char letter) {
    letter = tolower(letter);
    return letter == 'a'|| letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';

}

int contarVocal (Lista<char>&lis1, char vo) {
    int cont = 0;
    for (int i = 0; i < lis1.getTamanio(); i++) {
        if (lis1.getDato(i) == vo) {
            cont++;
        }
    }
    return cont;

    // if (lis1.esVacia() == true ) {
    //     return 1;
    // } YO LO EVALUE EN LA FUNCION. EN EL CODIGO DADO ESTA EVALUADO EN EL MAIN
}

int main () {

    std::cout << "Ejercicio 4 - U2 TP2 Listas" << std::endl;
    std::cout << "---------------------------" << std::endl;

    //ESCRITO POR MI
    // Lista<std::string> lista1;
    // std::string palabra;

    Lista <char> lista1;
    std::string palabra;
    char vocal;

    std::cout<<"Escriba una palabra: \n";
    std::getline(std::cin,palabra);
    // std::cout<<"-----------\n";
    // std::cout<<palabra<<std::endl;

    //inserto palabra separa letra por letra
    for (int i = 0; i < palabra.length(); i++) {
        char letra = palabra[i];
        lista1.insertarUltimo(letra);
    }

    if (lista1.esVacia()) {
        std::cout << "Lista vacia" << std::endl;
        return 0;
    }

    std::cout<<"Ingrese la vocal que desea contar: "<<std::endl;
    std::cin>>vocal;

    if (!esVocal(vocal)) {
        std::cout <<"La letra ingresada no es vocal"<<std::endl;
        return 0;
    }

    std::cout<<"La vocal ingresa es "<<vocal<<std::endl;
    std::cout<<"La cantidad de veces que aparece la vocal es \n";
    contarVocal(lista1, vocal);

    std::cout<<"La Lista es: "<<std::endl;
    lista1.print();

    return 0;
}


