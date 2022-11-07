#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string_view>
#include "SuffixArray.hpp"

/*Codigo extraido de Boletín 3 , proporcionado por Ayudante Alexander Irribarra*/

using namespace std;

SuffixArray::SuffixArray(const string& s){
    _t = s;
    _arr.resize(s.size() + 1); //Se crea un arreglo para los sufijos con tamaño longitud del texto mas un caracter especial '$'
    _t.push_back('$');
    _sv = string_view(_t); //Se crea un string view para poder tener referencias al texto original en lugar de reservar memoria para cada sufijo
    iota(_arr.begin(),_arr.end(),0); //el arreglo de sufjos contiene indices de 0 hasta lenght+1
    sort(_arr.begin(), _arr.end(), //se ordenan los indices segun la funcion creada abajo ordenando asi los sufijos por alfabeto
            [this](unsigned l, unsigned r) -> bool{
                return this->_sv.substr(l)< this->_sv.substr(r);
            }
        );  
}

unsigned SuffixArray::countMatches(const string& s){
    // true si es que el string s no esta antes
    auto lower = lower_bound(_arr.begin(), _arr.end(),s,
                [this](unsigned l, const string &s) -> bool{
                return _sv.substr(l) < s;
    });

    // true si es que el string s no esta antes
    auto upper = upper_bound(_arr.begin(), _arr.end(), s,
                [this](const string &s,unsigned l ) -> bool{
                return _sv.substr(l,s.size()) > s;
    });
    
    return distance(lower,upper);
}

