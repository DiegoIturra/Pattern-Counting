#include <bits/stdc++.h>
#include "fmindex.h"
using namespace std;


string FMIndex::BWTC(const string &source, map<char,int> &c){
    string L;
    string t = source;
    vector<unsigned> _arr(source.size()+1);
    t.push_back('$');
	string_view sv = string_view(t);
	iota(_arr.begin(),_arr.end(),0);
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

    map<char,int>::iterator it;
    int sum = 0,current = 0;
    for (it = c.begin(); it != c.end(); ++it){
    	current = it->second;
    	it->second = sum;
    	sum += current;
    }
    return L;
}

int FMIndex::Occ(char c, int k){
	int i = k/m;
	int sum = preOcc[c][i];
	for (int j = i*m ; j < k; ++j){
		if(L[j]==c)sum++;
	}
	return sum;
}


int FMIndex::LFmapping(int i){
	return C[L[i]] + Occ(L[i],i);
}

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

int FMIndex::count(const string &s){
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

void FMIndex::displayL(){
	cout<<L<<endl;
}

FMIndex::FMIndex(const string &T){
	m = 1000;
	L = BWTC(T,C);
	
}
