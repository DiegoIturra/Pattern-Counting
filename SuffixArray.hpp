#ifndef SUFFIX_ARRAY
#define SUFFIX_ARRAY

#include <vector>
#include <string_view>

using namespace std;

class SuffixArray{
	private:
		string _t;
        string_view _sv; //Es como un puntero pero sin almacenamiento
        vector<unsigned> _arr;

        bool compareSuffix(unsigned l,unsigned r);

	public:
		SuffixArray(const string& s);
		unsigned countMatches(const string& s);
};

#endif
