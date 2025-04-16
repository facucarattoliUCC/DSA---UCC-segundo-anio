cmake_minimum_required(VERSION 3.30)
project(U_II_Linked_List CXX)  # <-- CAMBIAMOS de C a CXX

set(CMAKE_CXX_STANDARD 11)     # <-- CAMBIAMOS de C_STANDARD a CXX_STANDARD

include_directories(.)

add_executable(main "Ejemplo Lista.h Nodo.h/main.cpp")
add_executable(U2TP2Ej4 U2TP2Ej4.cpp)
