# -----------------------------------------------------------------------------
# Archivo: CMakeLists.txt
# Descripción: Archivo de configuración principal de CMake para el proyecto TPI.
# Este archivo define los requisitos, configuraciones, dependencias y archivos
# fuente para la compilación del proyecto. Incluye configuraciones para la
# integración y ejecución de pruebas usando GoogleTest.
# Autor: Pablo
# Fecha: 2017
# -----------------------------------------------------------------------------

# Versión mínima requerida de CMake
cmake_minimum_required(VERSION 3.8)

# Nombre del proyecto
project(tpi)

# Establecemos el estándar C++11
set(CMAKE_CXX_STANDARD 11)

# Extendemos el PATH del módulo para incluir nuestros propios módulos CMake
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

# Añadimos el subdirectorio de GoogleTest para la compilación
add_subdirectory(lib/googletest-master)

# Incluimos los directorios de cabeceras de GoogleTest
include_directories(lib/googletest-master/googletest/include)

# Obtenemos los archivos de prueba
file(GLOB DIR_TESTS_EN "test/*.cpp")

# Definimos los archivos fuente del proyecto
set(SOURCE_FILES main.cpp
        auxiliares.cpp
        ejercicios.cpp
)

# Añadimos un ejecutable basado en los archivos fuente y de prueba
add_executable(tpi ${SOURCE_FILES}
        ${DIR_TESTS_EN}
        )

# Flags del compilador para cobertura y depuración
set(CMAKE_CXX_FLAGS "-g --coverage")
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)

# Establecemos el directorio de salida para los ejecutables compilados
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

# Vinculamos las bibliotecas de GoogleTest al proyecto
target_link_libraries(tpi gtest gtest_main)
