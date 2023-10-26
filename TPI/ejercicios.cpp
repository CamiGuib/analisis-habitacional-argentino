/*
  Archivo: ejercicios.cpp
  Proyecto para Algoritmos y Estructuras de Datos I, Facultad de Ciencias Exactas y Naturales, UBA
  Autores: Leandro Licari, Antony Suárez, Camila Guibaudo
  Fecha: 28/11/21
  Descripción: aquí están las implementaciones realizadas para solucionar los ejercicios planteados en el enunciado del TPI
*/

using namespace std;

// Inclusión de cabeceras
#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
    bool resp = false;

    resp = esValida(th,ti);

    return resp;
}
//*/

// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector<int> resultado(numeroDeHabitacionesMaximoEnRegion(th, region));
    for (int i = 0; i<resultado.size(); i++){
        resultado[i] = cantidadCasasDeNHabitacionesEnLaRegion(th, region, i+1);
    }
    return resultado;
}

// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    float proporcion = 0;
    vector<pair<int,float>> res;
    vector<int> reg = {1,40,41,42,43,44};
    for (int i = 0; i < CANTIDAD_DE_REGIONES; i++) {
        proporcionHogares(th,ti,reg[i],proporcion);
        res.push_back(make_pair(reg[i],proporcion));
    }

    return res;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    bool resp = false;

    if (t1i[0][INDANIO] < t2i[0][INDANIO] && t1i[0][INDTRIMESTRE] == t2i[0][INDTRIMESTRE]){
        resp = proporcionTeleworking(t1h,t1i) < proporcionTeleworking(t2h,t2i);
    }

    return  resp;
}

// Implementacion Problema 5
int costoSubsidioMejora( eph_h th, eph_i ti, int monto ){
    int resp = 0;

    if (monto > 0){
        for (int h = 0; h < th.size(); h++){
            if (th[h][II7] == 1 && (th[h][II2] < (cantHabitantes(th[h],ti) - 2))){
                resp = resp + monto;
            }
        }
    }

    return  resp;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    join_hi resp;
    int lTh = th.size(), lTi = ti.size(), habitantesHogar = 0;
    for (int i = 0; i < lTh; i++) {

        for (int j = 0; j < lTi && habitantesHogar < 21 ; ++j) {
            if (esSuHogar(th[i],ti[j])) {
                resp.push_back(make_pair(th[i],ti[j]));
            }
        }
    }
    return  resp;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU ( eph_h & th, eph_i & ti ) {
    ordenarThPorRegion(th);
    ordenarThPorCodusu(th);
    ordenarTiPorCodusu(th, ti);
    ordenarTiPorComponente(ti);
    return;
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    ordenarThPorIngresosDecrecientemente(th, ti);
    vector<hogar> laListaHomogeneaMasLarga = quedarseConLaListaMasLarga(listaDeListasHomogeneas(th, ti));
    ordenar(laListaHomogeneaMasLarga, th, ti);
    return laListaHomogeneaMasLarga;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {

    int l = th.size();
    for (int i = 0; i < l; i++) {
        if (th[i][REGION]== GBA) {
            th[i][REGION] = PAMPEANA;
        }
    }

}

// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
    vector < int > resp = {};

    for (int i = 0; i < distancias.size(); i++){
        if (i == 0){
            resp.push_back(cantidadHogaresEnEsteAnillo(th,0,distancias[0], centro));
        } else{
            resp.push_back(cantidadHogaresEnEsteAnillo(th,distancias[i-1],distancias[i], centro));
        }
    }

    return resp;
}

// Implementacion Problema 11
pair < eph_h, eph_i > quitarIndividuos( eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    eph_h rth = {};
    eph_i rti = {};
    pair < eph_h, eph_i > resp = make_pair(rth, rti);

    copiarIndividuosQueCumplenBusqueda(ti,busqueda,resp);
    copiarHogaresDeIndividuosQueCumplenBusqueda(th,resp);
    sacarDeTiIndividuosQueCumplenBusqueda(ti,resp);
    sacarDeThHogaresSinIndividuosQueCumplenBusqueda(th, ti, busqueda);

    return resp;
}
