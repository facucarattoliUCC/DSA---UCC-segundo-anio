#include <iostream>
#include <stdexcept>

int calculoFactorial (const int a) {
if (a == 0) {
    throw std::invalid_argument("El factorial de 0 no esta definifido");
}
if (a < 0) {
    throw std::invalid_argument("El factorial de numeros negativos no esta definido");
}
    int resultado = 1;
    for (int i = 1; i <= a ; i++) {
        resultado *= i;
    }
    return resultado;
}

int main () {

    std::cout<<"UnidadRepaso :: Ejercicio2"<<std::endl;

    int a;
    try {
        std::cout<<"Ingrese un numero para calcular su factorial: "<<std::endl;
        std::cin >> a;
        const int resultado = calculoFactorial(a);
        std::cout<<"El factorial del numero "<<a<<" es: "<< resultado <<std::endl;
    } catch (std::invalid_argument& e) {
        std::cerr<<"Error atrapada: "<<e.what()<<std::endl;
    }

    return 0;
}

