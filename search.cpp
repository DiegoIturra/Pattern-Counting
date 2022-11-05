#include <bits/stdc++.h>
#include "KMP.hpp"
#include "fmindex.hpp"
#include "SuffixArray.hpp"
using namespace std;

int espacio = 0;

void* operator new(size_t count){
	espacio += count;
	return malloc(count);
}

double variance(double *arr, int tam, double med){
	double var = 0;
	for (int i = 0; i < tam; ++i)
	{
		var += pow(arr[i]*1000 - med, 2);
	}
	return var/tam;
}

int main(int argc, char **argv){
	typedef std::size_t count_t, pos_t;
	int rep = atoi(argv[1]);//cantidad de repeticiones
	int len = atoi(argv[2]); //largo del texto
	int sSize = atoi(argv[3]); //largo del patron busacdo
	int option = atoi(argv[4]); //opcion de estructura
	//variables utilizadas
	chrono::time_point<chrono::high_resolution_clock> start, end;
	chrono::duration<double> diff;
	srand (time(NULL));
	ifstream file("data.txt");//archivo utilizado
	char *input = new char [len];
	file.read(input,len);
	string Sinput(input);
	string_view sv  = string_view(Sinput);
	double vals[rep];
	int espacioSS = 0;

	if(option == 1){
		SuffixArray SA(Sinput);
		KnuthMorrisPratt kmp(Sinput);
		for (int i = 0; i < rep; ++i){
			string searchStr = string(sv.substr((rand()%(len-sSize-1)),sSize));
			start = chrono::high_resolution_clock::now();
			espacio = 0;
			kmp.countMatches(searchStr);
			espacioSS += espacio;
			end = chrono::high_resolution_clock::now();
			diff = end - start;
			vals[i] = diff.count();
		}
	}
	else if(option == 2){
		SuffixArray SA(Sinput);
		for (int i = 0; i < rep; ++i){
			string searchStr = string(sv.substr((rand()%(len-sSize-1)),sSize));
			start = chrono::high_resolution_clock::now();
			espacio = 0;
			SA.countMatches(searchStr);
			espacioSS += espacio;
			end = chrono::high_resolution_clock::now();
			diff = end - start;
			vals[i] = diff.count();
		}
	}
	else{
		FMIndex fmi(Sinput,1000);
		for (int i = 0; i < rep; ++i){
			string searchStr = string(sv.substr((rand()%(len-sSize-1)),sSize));
			start = chrono::high_resolution_clock::now();
			espacio = 0;
			fmi.countMatches(searchStr);
			espacioSS += espacio;
			end = chrono::high_resolution_clock::now();
			diff = end - start;
			vals[i] = diff.count();
		}

	}

	double med = 0;

	for (int i = 0; i < rep; ++i){
		med += vals[i];
	}

	med = med*1000/rep;
	double var = variance(vals, rep, med);

	cout<<len<<";"<<sSize<<";"<<med<<";"<<var<<";"<<double(espacioSS)/rep<<endl;


	return 0;
} 