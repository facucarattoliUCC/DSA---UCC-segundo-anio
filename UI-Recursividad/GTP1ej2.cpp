#include <iostream>
#include <stdexcept> //Para usar std::runtime_error

int sumaRecursiva(int n){

    if (n == 0)
    {
        throw std::runtime_error("El numero debe ser mayor que 0");
    }
    if (n == 1) {
        return 1;
    }
    std::cout<< n << " + ";
    return n + sumaRecursiva(n - 1);
}

int main() {
    std::cout<<"Ejercicio 2 - Guia 1: Recursividad\n";
    std::cout<<"-----------------------------------\n";
    int a;
    try {
        std::cout<<"Ingrese los numeros enteros a sumar recursivamente: \n";
        std::cin >> a;
        std::cout<<"La suma de los primeros "<<a<<" numeros es: "<<sumaRecursiva(a);
    } catch (const std::exception& e) {
        std::cout<<"Error: "<<e.what()<<std::endl;
    }

    return 0;
}
