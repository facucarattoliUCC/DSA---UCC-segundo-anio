/*DUDAS
1) porque la funcion printPciente de la  class Paciente no debe recibir parametros? sino recibe parametros como
   imprime los atributos?
2) para la funcion atenderPaciente , si quiera pasarle como parametro un paciente y que desencole al paciente de
   acuerdo al paciente recibido por parametro. Como podria hacerlo ? Debo comparar con el nombre del paciente de
   la cola con el paciente recibido por parametro ?
 */

#include <iostream>
#include "Cola.h"
#include <stdexcept>
#include"Paciente.h"

void mostrarPaciente (Cola<Paciente>& col1) {
    Cola<Paciente> aux1;

    while (!col1.esVacia()) {
        Paciente paciente = col1.desencolar();
        std::cout<<"Nombre: "<< paciente.getNombre()
                 <<". Telefono: "<<paciente.getTelefono()
                 <<std::endl;
        aux1.encolar(paciente);
    }
    std::cout<<"***********************\n";
    while (!aux1.esVacia()) {
        col1.encolar(aux1.desencolar());
    }
}

void atenderPaciente (Cola<Paciente>& col2 /*, Paciente& pacien2*/) {

    if (col2.esVacia()) {
        std::cout<< "No hay pacientes en cola\n";
    } else {
        Paciente paciente = col2.desencolar();
        std::cout<< "El paciente "<< paciente.getNombre()<<" esta siendo atendido."<<std::endl;
    }

}


int main () {
    std::cout<<"UNIDAD IV QUEUE/COLA ::GUIA TP 4 - EJERCICIO 6::\n";
    std::cout<<"------------------------------------------------\n";

    Cola <Paciente> cola;
    int opcion;

    do {
        std::cout<<"Ingrese una opcion\n";
        std::cout<<"Opcion 1: Mostrar paciente\n";
        std::cout<<"Opcion 2: Agregar nuevo paciente a la cola\n";
        std::cout<<"Opcion 3: Atender paciente en espera\n";
        std::cout<<"Opcion 4: Salir del programa\n";
        std::cin>>opcion;

        switch(opcion) {

            //mostrar paciente
            case 1: {
                mostrarPaciente(cola);
                break;
            }

            //agregar nuevo paciente
            case 2: {
                std::string nombre;
                int telefono;

                std::cout<<"Ingrese el nombre\n";
                std::cin>>nombre;

                std::cout<<"Ingrese el telefono\n";
                std::cin>>telefono;

                Paciente paciente(nombre, telefono);
                cola.encolar(paciente);
                break;
            }

            //atender paciente en espera
            case 3: {
                atenderPaciente(cola);
                break;
            }

            //manejar datos pacientes
            case 4: {
                break;
            }


            default: {
                if (opcion > 4 || opcion < 1 ) {
                    std::cout<<"Ingrese una opcion valida\n";
                    std::cout<<"**************************\n";
                }
            }

        }

    } while( opcion != 4);


    return 0;
}
