## Descripción

Esta carpeta contiene la implementación en C++ de los enunciados especificados en el `TPE`. Además de la implementación, 
hemos incluido pruebas desarrolladas con GoogleTest para verificar la correctitud de nuestras soluciones. Estas pruebas 
están listas para ser ejecutadas y garantizan la funcionalidad de las implementaciones presentes.

## Estructura del código 

- `enunciado-TPI.pdf`: aquí figuran todas las preguntas a resolver en este trabajo práctico. 
- `ejercicios.cpp`: aquí está el código que se usa para resolver cada uno de los ejercicios enunciados en `enunciado-TPI.pdf`.
- `ejercicios.h`: headers de las funciones implementadas en `ejercicios.cpp`.
- `auxiliares.cpp`: aquí están volcadas todas las funciones auxiliares utilizadas en `ejercicios.cpp`.
- `auxiliares.h`: aquí están los headers de las funciones de `auxiliares.cpp`.
- `main.cpp`: punto de entrada del programa. Se encarga de iniciar y ejecutar las pruebas de GoogleTest.
- `CMakeLists.txt`: Archivo de configuración principal de CMake para el proyecto TPI. Este archivo define los requisitos,
configuraciones, dependencias y archivos fuente para la compilación del proyecto. Incluye configuraciones para la integración
y ejecución de pruebas usando GoogleTest.
- Tests: esta carpeta contiene todos los tests de GoogleTests utilizados para verificar la correctitud de los problemas
resueltos.
- Datos: aquí están volcados todos los archivos con los datos extraídos de www.indec.gob.ar/bases-de-datos.asp utilizados
para realizar este trabajo.
- Lib: en esta carpeta se encuentran todos los archivos necesarios para poder correr los tests de GoogleTest en formato
comprimido.


