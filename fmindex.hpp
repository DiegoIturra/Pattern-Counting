#ifndef FMINDEX
#define FMINDEX

#include <string>
#include <vector>
#include <map>
using namespace std;

class FMIndex {
private:
	int m;
	string L;
	map<char,int> C;
	map<char,vector<int>> preOcc;
	string BWTC(const string &source, map<char,int> &c);//se obtiene el BWT y el C
	int LFmapping(int i);
	int Occ(char c, int k);

public:
	
	FMIndex(const string &T, int mval);
	string extract();
	int countMatches(const string &s);
	void displayL();
};

#endif