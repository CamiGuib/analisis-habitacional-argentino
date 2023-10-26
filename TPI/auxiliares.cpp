/*
  Archivo: auxiliares.cpp
  Proyecto para Algoritmos y Estructuras de Datos I, Facultad de Ciencias Exactas y Naturales, UBA
  Autores: Leandro Licari, Antony Suárez, Camila Guibaudo
  Fecha: 28/11/21
  Descripción: aquí están las implementaciones de las funciones auxiliares utilizadas en las funciones de ejercicios.cpp
*/

//Inclusiones
#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"
#include <iostream>
#include <vector>
#include <fstream>

////////////////////////////////////////////////////////////////// Funciones generales ////////////////////////////////////////////////////////////////////

bool flotante_valido(float valor_esperado, float valor_recibido, float umbral) {
    return abs(valor_esperado - valor_recibido) < umbral;\
}

vector < vector < int > > leerEncuestaIH(string nombreArchivo) {
    char sep = ','; // separador del csv
    ifstream miArchivo;
    vector < vector < int > > t;
    string line="";
    miArchivo.open(nombreArchivo.c_str(), ifstream::in);
    if ( miArchivo.is_open() ) {
        /*header:*/getline(miArchivo, line);
        while ( getline(miArchivo, line) ) {
            vector<int> item;
            std::stringstream linestream(line);
            std::string value;
            while ( getline(linestream, value, sep) ) {
                item.push_back(stoi(value));
            }
            t.push_back(item);
        }
        miArchivo.close();
    } else
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    return t;
}

void leerEncuesta ( string filename , eph_h & th, eph_i & ti ){
    string path = "datos/";
    th = leerEncuestaIH(path+filename+".th");
    ti = leerEncuestaIH(path+filename+".ti");
}

void leerEncuestaRes ( string filename , eph_h & th){
    string path = "datos/";
    th = leerEncuestaIH(path+filename+".th");
}

bool esSuHogar(hogar h, individuo p) {

    return  h[HOGCODUSU] == p[INDCODUSU];
}

////////////////////////////////////////////////////////////////// Ejercicio 1.////////////////////////////////////////////////////////////////////

bool esMatriz(vector<vector<int>> t){
    bool res = true;

    for (int i = 0; i < t.size(); i++){
        for (int j = 0; j < t.size(); j++){
            if (t[i].size() != t[j].size()){
                res = false;
            }
        }
    }

    return res;
}

bool cantidadCorrectaDeColumnasI(eph_i ti){
    bool res = true;

    for (int i = 0; i < ti.size(); i++){
        res = res && (ti[i].size() == FILAS_INDIVIDUO);
    }

    return res;
}

bool cantidadCorrectaDeColumnasH(eph_h th){
    bool res = true;

    for (int h = 0; h < th.size(); h++){
        res = res && (th[h].size() == FILAS_HOGAR);
    }

    return res;
}

bool hayHogarConCodigo(eph_h th, int c){
    bool res = false;

    for (int h = 0; h < th.size(); h++) {
        if (th[h][HOGCODUSU] == c){
            res = true;
        }
    }

    return res;
}

bool hayIndividuoConCodigo(eph_i ti, int c){
    bool res = false;

    for (int i = 0; i < ti.size(); i++) {
        if (ti[i][INDCODUSU] == c){
            res = true;
        }
    }

    return res;
}

bool hayIndividuosSinHogares(eph_i ti, eph_h th){
    bool res = false;

    for (int i = 0; i < ti.size(); i++){
        if (!hayHogarConCodigo(th,ti[i][INDCODUSU])){
            res = true;
        }
    }

    return res;
}

bool hayHogaresSinIndividuos(eph_i ti, eph_h th){
    bool res = false;

    for (int h = 0; h < th.size(); h++){
        if (!hayIndividuoConCodigo(ti,th[h][HOGCODUSU])){
            res = true;
        }
    }

    return  res;
}

bool hayRepetidosI(eph_i ti){
    bool res = false;

    for (int i = 0; i < ti.size(); i++){
        for (int j = 0; j < ti.size(); j++){
            if (i != j){
                res = res || ((ti[i][INDCODUSU] == ti[j][INDCODUSU]) && ti[i][COMPONENTE] == ti[j][COMPONENTE]);
            }
        }
    }

    return  res;
}

bool hayRepetidosH(eph_h th){
    bool res = false;

    for (int h = 0; h < th.size(); h++){
        for (int j = 0; j < th.size(); j++){
            if (h != j){
                res = res || th[h][HOGCODUSU] == th[j][HOGCODUSU];
            }
        }
    }
    return  res;
}

bool mismoAnioYTrimestre(eph_i ti, eph_h th){
    bool res = true;
    int anio = ti[0][INDANIO];
    int trimestre = ti[0][INDTRIMESTRE];

    for (int i = 0; i < ti.size(); i++){
        if (ti[i][INDANIO] != anio || ti[i][INDTRIMESTRE] != trimestre){
            res = false;
        }
    }
    for (int h = 0; h < th.size(); h++){
        if (th[h][HOGANIO] != anio || th[h][HOGTRIMESTRE] != trimestre){
            res = false;
        }
    }

    return  res;
}

int cantHabitantes(hogar h, eph_i ti){
    int habitantes = 0;

    for (int i = 0; i < ti.size(); i++){
        if (ti[i][INDCODUSU] == h[HOGCODUSU]){
            habitantes++;
        }
    }
    return habitantes;
}

bool menosDe21MiembrosPorHogar(eph_i ti, eph_h th){
    bool res = true;

    for (int h = 0; h < th.size(); h++){
        if (cantHabitantes(th[h],ti) >= 21){
            res = false;
        }
    }

    return  res;
}

bool cantidadValidaDormitorios(eph_h th){
    bool res = true;

    for (int h = 0; h < th.size(); h++){
        if (th[h][IV2] < th[h][II2]){
            res = false;
        }
    }

    return res;
}

bool individuoValido(individuo i){
    bool res = true;

    res = res && (i[INDCODUSU] > 0) && (i[COMPONENTE] > 0);
    res = res && ((i[INDTRIMESTRE] > 0) && (i[INDTRIMESTRE] <= 4));
    res = res && ((i[CH4] > 0) && (i[CH4] <= 2)) && (i[CH6] >= 0);
    res = res && (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1);
    res = res && ((i[ESTADO]) >= -1 && (i[ESTADO] <= 1));
    res = res && ((i[CAT_OCUP]) >= 0 && (i[CAT_OCUP] <= 4));
    res = res && ((i[p47T]) >= 0 || (i[p47T] == -1));
    res = res && ((i[PP04G]) >= 0 && (i[PP04G] <= 10));

    return  res;
}

bool valoresEnRangoI(eph_i ti){
    bool res = true;

    for (int i = 0; i < ti.size(); i++){
        if (!individuoValido(ti[i])){
            res = false;
        }
    }

    return  res;
}

bool hogarValido(hogar h){
    bool res = true;

    res = res && (h[HOGCODUSU] > 0) && (h[HOGTRIMESTRE] > 0) && (h[HOGTRIMESTRE] <= 4);
    res = res && (h[II7] > 0) && (h[II7] <= 3);
    res = res && ((h[REGION] == 1) || ((h[REGION] >= 40) && (h[REGION] <= 44)));
    res = res && ((h[MAS_500] == 0) || (h[MAS_500] == 1));
    res = res && (h[IV1] > 0) && (h[IV1] <= 5);
    res = res && (h[IV2] > 0) && (h[II2] >= 1);
    res = res && ((h[II3] == 1) || (h[II3] == 2));

    return res;
}

bool valoresEnRangoH(eph_h th){
    bool res = true;

    for (int h = 0; h < th.size(); h++){
        if (!hogarValido(th[h])){
            res = false;
        }
    }

    return res;
}

bool esValida (eph_h th, eph_i ti){
    bool res;

    res = (ti.size() > 0) && (th.size() > 0) && esMatriz(th) && esMatriz(ti);
    res = res && cantidadCorrectaDeColumnasI(ti) && cantidadCorrectaDeColumnasH(th);
    res = res && !hayIndividuosSinHogares(ti,th) && !hayHogaresSinIndividuos(ti,th);
    res = res && !hayRepetidosI(ti) && !hayRepetidosH(th);
    res = res && mismoAnioYTrimestre(ti,th) && menosDe21MiembrosPorHogar(ti,th);
    res = res && cantidadValidaDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th);

    return res;
}

////////////////////////////////////////////////////////////////// Ejercicio 2 //////////////////////////////////////////////////////////////////////////

int numeroDeHabitacionesMaximoEnRegion(eph_h th, int region){
    int res = 0;
    for (int i = 0; i < th.size(); i++){
        if (th[i][IV2] >= res && th[i][REGION] == region){
            res = th[i][IV2];
        }
    }
    return res;
}

int cantidadCasasDeNHabitacionesEnLaRegion(eph_h th, int region, int N){
    int contador = 0;
    for (int i = 0; i < th.size(); i++){
        if (th[i][IV1] == CASA && th[i][IV2] == N && th[i][REGION] == region){
            contador++;
        }
    }
    return contador;
}


////////////////////////////////////////////////////////////////// Ejercicio 3 //////////////////////////////////////////////////////////////////////////


void esHogarValido(hogar h, int region, bool & var) {
    var = h[MAS_500] ==  0 && h[IV1] == CASA && h[REGION] == region;
}

void existeHacinamiento (hogar h, eph_i ti, bool & variable) {
    int cantidadHabitantes = cantHabitantes(h, ti);
    variable = cantidadHabitantes > 3*h[II2];
}

void proporcionHogares (eph_h th, eph_i ti, int parametro,  float & proporcion) {
    float totalHogares=0 , hogaresConHacinamiento = 0;
    int fH = th.size();
    bool datoValido = true;
    for (int i = 0; i < fH; i++){
        esHogarValido(th[i], parametro,datoValido);
        if (datoValido){
            existeHacinamiento(th[i],ti,datoValido);
            if (datoValido){
                hogaresConHacinamiento++;
            }
            totalHogares++;
        }
    }
    if(totalHogares == 0){
        proporcion = 0;
    } else{
        proporcion = hogaresConHacinamiento/totalHogares;
    }
}

////////////////////////////////////////////////////////////////// Ejercicio 4 //////////////////////////////////////////////////////////////////////////

bool individuoEnHogarValido(individuo ind, eph_h th){
    bool res = false;

    for (int h = 0; h < th.size(); h++){
        if (th[h][HOGCODUSU] == ind[INDCODUSU] && th[h][MAS_500] == 1 && (th[h][IV1] == CASA || th[h][IV1] == 2)){
            res = true;
        }
    }

    return  res;
}

float cantidadIndividuosQueTrabajan(eph_h th, eph_i ti){
    float cant = 0;

    for (int i = 0; i < ti.size(); i++){
        if (ti[i][ESTADO] == OCUPADO && individuoEnHogarValido(ti[i], th)){
            cant++;
        }
    }

    return cant;
}

bool suHogarTieneEspacioDeTrabajo(individuo ind, eph_h th){
    bool res = false;

    for (int h = 0; h < th.size(); h++){
        if (th[h][HOGCODUSU] == ind[INDCODUSU] && th[h][II3] == 1){
            res = true;
        }
    }

    return res;
}

float cantidadIndividuosTeleworking(eph_h th, eph_i ti){
    float cant = 0;

    for (int i = 0; i < ti.size(); i++){
        if (ti[i][ESTADO] == OCUPADO && ti[i][PP04G] == EN_ESTE_HOGAR && suHogarTieneEspacioDeTrabajo(ti[i], th) &&
            individuoEnHogarValido(ti[i],th)){
            cant++;
        }
    }

    return cant;
}

float proporcionTeleworking(eph_h th, eph_i ti){
    float proporcion;
    float trabajadores;
    trabajadores = cantidadIndividuosQueTrabajan(th,ti);

    if (trabajadores > 0){
        proporcion = cantidadIndividuosTeleworking(th,ti) / trabajadores;
    } else{
        proporcion = 0;
    }

    return proporcion;
}

////////////////////////////////////////////////////////////////// Ejercicio 7 //////////////////////////////////////////////////////////////////////////

void ordenarThPorRegion(eph_h &th) {
    for (int j = th.size() - 1; j > 0; j--) {
        if (th[j][REGION] < th[j - 1][REGION]) {
            vector<int> guardar = th[j];
            th[j] = th[j - 1];
            th[j - 1] = guardar;
            j = th.size();
        }
    }
}

void ordenarThPorCodusu(eph_h &th) {
    for (int j = th.size() - 1; j > 0; j--) {
        if (th[j][REGION] == th[j - 1][REGION] && th[j][HOGCODUSU] < th[j - 1][HOGCODUSU]) {
            vector<int> guardar = th[j];
            th[j] = th[j - 1];
            th[j - 1] = guardar;
            j = th.size();
        }
    }
}



void ordenarTiPorComponente(eph_i &ti) {
    for (int j = ti.size() - 1; j > 0; j--) {
        if (ti[j][INDCODUSU] == ti[j - 1][INDCODUSU] && ti[j][COMPONENTE] < ti[j - 1][COMPONENTE]) {
            vector<int> guardar = ti[j];
            ti[j] = ti[j - 1];
            ti[j - 1] = guardar;
            j = ti.size();
        }
    }
}

vector<int> hogarAsociadoAEsteIndividuo(int filaTi, eph_h th, eph_i ti){
    vector<int> res;
    for(int i=0; i<th.size(); i++){
        if (th[i][HOGCODUSU] == ti[filaTi][INDCODUSU]){
            res = th[i];
        }
    }
    return res;
}


bool suHogarEstaAntes(int filaTi1, int filaTi2, eph_h th, eph_i ti){ //Indica si el hogar del individuo ti[filaTi1] aparece antes que el hogar del individuo ti[filaTi2] en la tabla th.
    bool res = false;
    if (hogarAsociadoAEsteIndividuo(filaTi1,th,ti)[REGION] == hogarAsociadoAEsteIndividuo(filaTi2,th,ti)[REGION]){
        if (hogarAsociadoAEsteIndividuo(filaTi1,th,ti)[HOGCODUSU] < hogarAsociadoAEsteIndividuo(filaTi2,th,ti)[HOGCODUSU]) {
            res = true;
        }
    } else if (hogarAsociadoAEsteIndividuo(filaTi1,th,ti)[REGION] < hogarAsociadoAEsteIndividuo(filaTi2,th,ti)[REGION]){
        res = true;
    } else {
        res = false;
    }
    return res;
}


void ordenarTiPorCodusu(eph_h &th, eph_i &ti){
    for (int j = ti.size() - 1; j > 0; j--) {
        if (suHogarEstaAntes(j, j-1, th, ti)) {
            vector<int> guardar = ti[j];
            ti[j] = ti[j - 1];
            ti[j - 1] = guardar;
            j = ti.size();
        }
    }
}


////////////////////////////////////////////////////////////////// Ejercicio 8 //////////////////////////////////////////////////////////////////////////

int ingresoTotalDeEsteHogar(int codusu, eph_h th, eph_i ti){
    int ingresoTotal = 0;
    for (int i=0; i<ti.size(); i++){
        if (ti[i][INDCODUSU] == codusu && ti[i][p47T] != -1){
            ingresoTotal = ingresoTotal + ti[i][p47T];
        }
    }
    return ingresoTotal;
}

void ordenarThPorIngresosDecrecientemente(eph_h &th, eph_i &ti) {
    for (int j = th.size() - 1; j > 0; j--) {
        if (ingresoTotalDeEsteHogar(th[j][HOGCODUSU], th, ti) > ingresoTotalDeEsteHogar(th[j-1][HOGCODUSU], th, ti)) {
            vector<int> guardar = th[j];
            th[j] = th[j - 1];
            th[j - 1] = guardar;
            j = th.size();
        }
    }
}

vector<vector<hogar>> listaDeListasHomogeneas(eph_h &th, eph_i &ti){
    vector<vector<hogar>> listaDeListasDeHogares = {};
    for (int i=0; i<th.size(); i++){
        for (int j=i+1; j<th.size(); j++){
            int dif = ingresoTotalDeEsteHogar(th[i][HOGCODUSU],th,ti) - ingresoTotalDeEsteHogar(th[j][HOGCODUSU],th,ti);
            vector<hogar> listaHomogenea = {};
            listaHomogenea.push_back(th[i]);
            listaHomogenea.push_back(th[j]);
            for (int k=j+1; k<th.size(); k++){
                if (ingresoTotalDeEsteHogar(listaHomogenea[listaHomogenea.size()-1][HOGCODUSU],th,ti) - ingresoTotalDeEsteHogar(th[k][HOGCODUSU],th,ti) == dif && dif>0){
                    listaHomogenea.push_back(th[k]);
                }
            }
            if (listaHomogenea.size() >= 3){
                listaDeListasDeHogares.push_back(listaHomogenea);
            }
        }
    }
    return listaDeListasDeHogares;
}

vector<hogar> quedarseConLaListaMasLarga(vector<vector<hogar>> v){
    if (v.size() == 0) {
        return {};
    }else{
        vector<hogar> res = v[0];
        for (int i = 0; i < v.size(); i++) {
            if (v[i].size() >= res.size()) {
                res = v[i];
            }
        }
        return res;
    }
}

void ordenar(vector<hogar> &v, eph_h th, eph_i ti){
    for (int j = v.size() - 1; j > 0; j--) {
        if (ingresoTotalDeEsteHogar(v[j][HOGCODUSU], th, ti) < ingresoTotalDeEsteHogar(v[j-1][HOGCODUSU], th, ti)) {
            vector<int> guardar = v[j];
            v[j] = v[j - 1];
            v[j - 1] = guardar;
            j = v.size();
        }
    }
}

////////////////////////////////////////////////////////////////// Ejercicio 10 //////////////////////////////////////////////////////////////////////////

float distancia(int latC, int lonC, int latH, int lonH){
    float dist;
    dist = sqrt(pow((latC - latH),2) + pow((lonC-lonH),2));
    return dist;
}

int cantidadHogaresEnEsteAnillo(eph_h th, int distMin, int distMax, pair <int,int> centro){
    int cont = 0;
    float dist;

    for (int h = 0; h < th.size(); h++){
        dist = distancia(centro.first,centro.second,th[h][HOGLATITUD],th[h][HOGLONGITUD]);
        if (dist > distMin && dist <= distMax){
            cont++;
        }
    }

    return cont;
}


////////////////////////////////////////////////////////////////// Ejercicio 11 //////////////////////////////////////////////////////////////////////////

void cambiarPorElUltimo(vector<vector<dato>>& t, vector<dato> cambio, int indiceDelCambio){
    vector<dato> aux;
    aux = t[t.size()-1];
    t[t.size()-1] = cambio;
    t[indiceDelCambio] = aux;
}


bool cumpleBusqueda(individuo ind, vector <pair<int, dato>> busqueda){
    bool res = true;

    for (int b = 0; b < busqueda.size(); b++){
        if (ind[busqueda[b].first] != busqueda[b].second){
            res = false;
        }
    }

    return  res;
}


void copiarIndividuosQueCumplenBusqueda(eph_i ti,vector <pair<int, dato>> busqueda, pair <eph_h, eph_i>& resp){
    bool cumplio = false;
    //Veo los individuos que cumplen la busqueda y los agrego a resp.second
    for (int i = 0; i < ti.size(); i++){
        if (cumpleBusqueda(ti[i],busqueda)){
            resp.second.push_back(ti[i]);
        }
    }
}


void copiarHogaresDeIndividuosQueCumplenBusqueda(eph_h th, pair <eph_h, eph_i>& resp){
    //Ahora agrego a resp.first todos los hogares de los individuos que cumplen la búsqueda
    for (int h = 0; h < th.size(); h++){
        bool mismoHogarDelIndividuo = false;
        for (int indQ = 0; indQ < resp.second.size(); indQ++){
            if (resp.second[indQ][INDCODUSU] == th[h][HOGCODUSU]){
                mismoHogarDelIndividuo = true;
            }
        }
        if (mismoHogarDelIndividuo){
            resp.first.push_back(th[h]);
        }
    }
}


void sacarDeTiIndividuosQueCumplenBusqueda(eph_i& ti, pair <eph_h, eph_i>& resp){
    //Ahora voy a sacar de ti, todos los individuos que cumplen la búsqueda
    int nuevaLongitudTi;
    nuevaLongitudTi = ti.size();
    for (int indQ = 0; indQ < resp.second.size(); indQ++) {
        for (int i = 0; i < nuevaLongitudTi; i++){
            if(resp.second[indQ][INDCODUSU] == ti[i][INDCODUSU] &&
               resp.second[indQ][COMPONENTE] == ti[i][COMPONENTE]){
                cambiarPorElUltimo(ti,ti[i],i);
                ti.pop_back();
                i = -1;
                nuevaLongitudTi--;
            }
        }
    }
}


bool existeIndividuoEnEsteHogarQueNoCumplaBusqueda(hogar h, eph_i ti, vector <pair<int, dato>> busqueda){
    bool res = false;

    for (int i = 0; i < ti.size(); i++){
        if (ti[i][INDCODUSU] == h[HOGCODUSU] && !cumpleBusqueda(ti[i],busqueda)){
            res = true;
        }
    }

    return res;
}


void sacarDeThHogaresSinIndividuosQueCumplenBusqueda(eph_h& th, eph_i ti, vector <pair<int, dato>> busqueda){
    //Ahora de th, saco los hogares dónde todos sus individuos cumplen la búsqueda.
    //Y los hogares que tienen al menos un individuo que no cumpla la búsqueda, no los saco.
    int nuevaLongitudTh;
    nuevaLongitudTh = th.size();

    //for (int h = 0; h < th.size(); h++){
    for (int h = 0; h < nuevaLongitudTh; h++){
        if(!existeIndividuoEnEsteHogarQueNoCumplaBusqueda(th[h], ti, busqueda)){
            cambiarPorElUltimo(th,th[h],h);
            th.pop_back();
            h = -1;
            nuevaLongitudTh--;
        }
    }
}