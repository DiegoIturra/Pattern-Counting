#include "fmindex.h"
#include <algorithm>
using namespace std;

string FMIndex::BWTC(string source, map<char,int> &c){
    string L;
    source.push_back(char(4));
    vector<string> rotations;
    for (int i = 0; i < source.size(); ++i)
    {
        rotations.push_back(source);
        rotate(source.begin(), source.begin() + 1, source.end());
    }
    sort(rotations.begin(),rotations.end());

    for (int i = 0; i < source.size(); ++i)
    {
        L.push_back(rotations[i][source.size()-1]);
        c[rotations[i][source.size()-1]]++;
    }
    map<char,int>::iterator it;
    int sum = 0,current = 0;
    for (it = c.begin(); it != c.end(); ++it)
    {
    	current = it->second;
    	it->second = sum;
    	sum += current;
    }
    return L;
}

int FMIndex::Occ(char c, int k){
	int sum = 0;
	for (int i = 0; i < k; ++i)
	{
		if(L[i]==c)sum++;
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

FMIndex::FMIndex(const string &T){
	L = BWTC(T,C);
}
