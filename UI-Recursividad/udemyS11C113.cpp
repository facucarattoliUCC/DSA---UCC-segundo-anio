#include <iostream>

unsigned long long Fibonacci (unsigned long long nro) {

    //base case
    if (nro <= 1) {
        return nro;
    }

    //Quiero mostrar como trabaja la recursion imprimiendo la secuencia de
    //std::cout << nro << ","<<nro + 1<<" ,"<<nro+2<<std::endl;

    //call function itself. Recursion
    return Fibonacci(nro-1)+Fibonacci(nro-2);
}

int main () {

    std::cout << Fibonacci(20)<<std::endl;

    return 0;
}