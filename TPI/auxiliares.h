/*
  Archivo: auxiliares.h
  Proyecto para Algoritmos y Estructuras de Datos I, Facultad de Ciencias Exactas y Naturales, UBA
  Autores: Leandro Licari, Antony Suárez, Camila Guibaudo
  Fecha: 28/11/21
  Descripción: aquí están las declaraciones correspondientes a las funciones de auxiliares.cpp
*/

using namespace std;

// Guardias de Inclusión
#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

// Inclusiones
#include "definiciones.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "definiciones.h"

// Funciones generales
bool flotante_valido(float valor_esperado, float valor_recibido, float umbral);
vector<vector<int>> leerEncuestaIH( string nombreArchivo );
void leerEncuesta ( string filename, eph_h & th, eph_i & ti );
void leerEncuestaRes ( string filename , eph_h & th);

// Funciones Ejercicio 1
bool esValida(eph_h th, eph_i ti);
bool esMatriz(vector<vector<int>> t);
bool cantidadCorrectaDeColumnasI(eph_i ti);
bool cantidadCorrectaDeColumnasH(eph_h th);
bool hayIndividuosSinHogares(eph_i ti, eph_h th);
bool hayHogaresSinIndividuos(eph_i ti, eph_h th);
bool hayHogarConCodigo(eph_h th, int c);
bool hayIndividuoConCodigo(eph_i ti, int c);
bool hayRepetidosI(eph_i ti);
bool hayRepetidosH(eph_h th);
bool mismoAnioYTrimestre(eph_i ti,eph_h th);
int cantHabitantes(hogar h, eph_i ti);
bool menosDe21MiembrosPorHogar(eph_i ti,eph_h th);
bool cantidadValidaDormitorios(eph_h th);
bool valoresEnRangoI(eph_i ti);
bool individuoValido(individuo i);
bool valoresEnRangoH(eph_h th);
bool hogarValido(hogar h);

// Funciones Ejercicio 2
int numeroDeHabitacionesMaximoEnRegion(eph_h th, int region);
int cantidadCasasDeNHabitacionesEnLaRegion(eph_h th, int region, int N);
vector<int> eliminarCerosAlFinal(vector<int> v);

// Funciones Ejercicio 3
void esHogarValido(hogar h, int region, bool & var);
void existeHacinamiento (hogar h, eph_i ti, bool & variable);
void proporcionHogares (eph_h th, eph_i ti, int parametro,  float & proporcion);
bool esSuHogar(hogar h, individuo p);

// Funciones Ejercicio 4
float proporcionTeleworking(eph_h th, eph_i ti);
float cantidadIndividuosQueTrabajan(eph_h th, eph_i ti);
bool individuoEnHogarValido(individuo ind, eph_h th);
float cantidadIndividuosTeleworking(eph_h th, eph_i ti);
bool suHogarTieneEspacioDeTrabajo(individuo ind, eph_h th);

// Funciones Ejercicio 7
void ordenarThPorRegion(eph_h &th);
void ordenarThPorCodusu(eph_h &th);
void ordenarTiPorCodusu(eph_h &th, eph_i &ti);
bool suHogarEstaAntes(int filaTi1, int filaTi2, eph_h th, eph_i ti);
vector<int> hogarAsociadoAEsteIndividuo(int filaTi, eph_h th, eph_i ti);
void ordenarTiPorComponente(eph_i &ti);

// Funciones Ejercicio 8
int ingresoTotalDeEsteHogar(int codusu, eph_h th, eph_i ti);
void ordenarThPorIngresosDecrecientemente(eph_h &th, eph_i &ti);
vector<vector<hogar>> listaDeListasHomogeneas(eph_h &th, eph_i &ti);
vector<hogar> quedarseConLaListaMasLarga(vector<vector<hogar>> v);
void ordenar(vector<hogar> &v, eph_h th, eph_i ti);

// Funciones Ejercicio 10
float distancia(int latC, int lonC, int latH, int lonH);
int cantidadHogaresEnEsteAnillo(eph_h th, int distMin, int distMax, pair <int,int> centro);

// Funciones Ejercicio 11
void copiarIndividuosQueCumplenBusqueda(eph_i ti,vector <pair<int, dato>> busqueda, pair <eph_h, eph_i>& resp);
void copiarHogaresDeIndividuosQueCumplenBusqueda(eph_h th, pair <eph_h, eph_i>& resp);
void sacarDeTiIndividuosQueCumplenBusqueda(eph_i& ti, pair <eph_h, eph_i>& resp);
void sacarDeThHogaresSinIndividuosQueCumplenBusqueda(eph_h& th, eph_i ti, vector <pair<int, dato>> busqueda);
bool cumpleBusqueda(individuo ind, vector <pair<int, dato>> busqueda);
void cambiarPorElUltimo(vector<vector<dato>>& t, vector<dato> cambio, int indiceDelCambio);
bool existeIndividuoEnEsteHogarQueNoCumplaBusqueda(hogar h, eph_i ti, vector <pair<int, dato>> busqueda);

#endif //SOLUCION_AUXILIARES_H
