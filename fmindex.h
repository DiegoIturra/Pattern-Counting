#include <string>
#include <vector>
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
	
	FMIndex(const string &T);
	string extract();
	int count(const string &s);
	void displayL();
};
