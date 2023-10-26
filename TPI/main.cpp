/*
  Archivo: main.cpp
  Proyecto para Algoritmos y Estructuras de Datos I, Facultad de Ciencias Exactas y Naturales, UBA
  Autores: Leandro Licari, Antony Suárez, Camila Guibaudo
  Fecha: 28/11/21
  Descripción: Este archivo es el punto de entrada del programa y se encarga de iniciar y ejecutar las pruebas con Google Test.
*/

#include <iostream>
#include "gtest/gtest.h"

int main(int argc, char **argv) {
    std::cout << "Implementación TPI" << std::endl;

    // Inicialización y ejecución de Google Test
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}