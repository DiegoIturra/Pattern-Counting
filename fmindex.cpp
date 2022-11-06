#include <bits/stdc++.h>
#include "fmindex.hpp"
using namespace std;

/*
Esta funcion crea el BWT, C y precomputan ciertos valores de Occ
Primero que todo se obtienen los indices relacionados al suffix array
luego con esos indices se obtiene el BWT al tomar el valor anterior a
cada sufijo(el ulimo caracter de cada rotacion), a su vez se va inser-
tando en C para contar cuantas instancias hay de cada caracter y al
mismo tiempo se arma PreOcc agregando como 0 a todos los valores que
tendra dentro de la tabla precomputada y cada vez que se llegue a una
cantidad definida de m elementos se pasará al siguiente elemento de la
tabla con la intencion de tener marcas de cuantos elementos hay de cada
caracter en distintos puntos de L haciendo así Occ constante.
*/
string FMIndex::BWTC(const string &source, map<char,int> &c){
    string L;
    string t = source;
    vector<unsigned> _arr(source.size()+1);
    t.push_back(char(4));
	string_view sv = string_view(t);
	iota(_arr.begin(),_arr.end(),0);//se crea arreglo de 0 a souce.size()+1
	sort(_arr.begin(), _arr.end(), //se ordenan los indices segun la funcion creada abajo ordenando asi los sufijos por alfabeto
			[sv](unsigned l, unsigned r) -> bool{
				return sv.substr(l)< sv.substr(r);
			}
		);

    for (int i = 0; i < t.size(); ++i){
    	int j = _arr[i] - 1;
    	if(j < 0 )j += t.size();
        L.push_back(t[j]);
        c[t[j]]++;

        if(!preOcc[t[j]].size()){
        	for (int l = 0; l < source.size()/m + 2; ++l)
        		preOcc[t[j]].push_back(0);
        }

        if(i%m == 0 and i != 0){
        	map<char, vector<int>>::iterator it;
        	for(it = preOcc.begin(); it !=preOcc.end(); it++){
        		it->second[i/m + 1] = it->second[i/m];
        	}
        }
        preOcc[t[j]][i/m + 1]++; 
    }
    //se van sumando las cantidades obtenidas para lograr el formato deseado
    map<char,int>::iterator it;
    int sum = 0,current = 0;
    for (it = c.begin(); it != c.end(); ++it){
    	current = it->second;
    	it->second = sum;
    	sum += current;
    }
    return L;
}

/*
Esta funcion cuenta la cantidad de instancias de un elemento
dentro de los primeros k caracteres, utiliza el valor precomputado
menor mas cercano y recorre los elementos siguientes sumando al valor
precomputado
*/
int FMIndex::Occ(char c, int k){
	int i = k/m;
	int sum = preOcc[c][i];
	for (int j = i*m ; j < k; ++j){
		if(L[j]==c)sum++;
	}
	return sum;
}

/*int FMIndex::Occ(char c, int k){
	int sum = 0;
	for (int j = 0 ; j < k; ++j){
		if(L[j]==c)sum++;
	}
	return sum;
}*/

/*
retorna el indice del elemento correspondiente a el sufijo que
comienza con el caracter con el que termina el sujijo de indice i
*/
int FMIndex::LFmapping(int i){
	return C[L[i]] + Occ(L[i],i);
}

/*
Comenzando desde el final se arma la string original
haciendo uso de LFmapping
*/
string FMIndex::extract(){
	string T;
	int pos = 0;
	for (int i = 0; i < L.size(); ++i)
	{
		T.insert(T.begin(), L[pos]);
		pos = LFmapping(pos);
	}
	return T;
}

/*
Se toman los rangos em los que se encuentran los caracteres
buscados necesarios para armar el patron buscado comenzando
por el ultimo caracter. Para esto se hace uso de Occ para asi
conocer el primer caracter valido y el ultimo, se agrega C[c]
para tomar en cuenta el desfase, luego dentro del rango obtenido
se busca el rango del siguiente caracter y se sigue asi iterativamente
hasta que no se encuentre un rango valido o se obtenga la cantidad de 
coincidencias
*/
int FMIndex::countMatches(const string &s){
	int top = 0;
	int bot = L.size();
	int i = s.size()-1;
	while(i >= 0 and bot > top){
		char c = s[i];
		top = C[c] + Occ(c,top);
		bot = C[c] + Occ(c,bot);
		i--;
	}
	if(bot-top > 0)return bot-top;
	return 0;
}

//imprime L en pantalla
void FMIndex::displayL(){
	cout<<L<<endl;
}
//construye FMIndex creando las estructuras clave
FMIndex::FMIndex(const string &T, int mval){
	m = mval;
	L = BWTC(T,C);
	
}
