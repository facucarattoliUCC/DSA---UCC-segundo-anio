#include <iostream>

void marcarAsiento(bool* asiento) {
*asiento = true;
}


int main () {
    std::cout<<"UnidadRepaso :: Ejercicio3"<<std::endl;
    const int nroAsientos = 100;
    int asientos[nroAsientos] = {false}; //false significa que todos los asientos estan libres


    return 0;
}
