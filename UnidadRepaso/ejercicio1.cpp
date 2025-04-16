#include <iostream>

void intercambiarJugo(float &naranja, float &manzana) {
    const float temp = naranja;
    naranja = manzana;
    manzana = temp;
}

int main () {

    std::cout<<"UnidadRepaso :: Ejercicio1"<<std::endl;
    std::cout<<"-----------------------------\n";
    float naranja, manzana;
    std::cout<<"Ingrese cantidad de jugo naranjas: \n";
    std::cin>>naranja;
    std::cout<<"Ingrese cantidad de jugo manzana: \n";
    std::cin>>manzana;

    intercambiarJugo(naranja, manzana);
    std::cout<<"Intercambiando jugos:\n"
             <<"Jugo manzana "<<manzana<<"\n"
             <<"Jugo Naranja "<<naranja<<"\n";

    return 0;
}