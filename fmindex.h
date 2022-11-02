using namespace std;

class FMIndex {
private:
	string L;
	map<char,int> C;
	string BWTC(string source, map<char,int> &c);//se obtiene el BWT y el C
	
	int LFmapping(int i);

public:
	int Occ(char c, int k);
	FMIndex(const string &T);
	string extract();
	int count(const string &s);
};