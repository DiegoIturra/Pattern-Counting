#ifndef KMP
#define KMP

#include <vector>
#include <string>

using namespace std;

class KnuthMorrisPratt{
    private:
        string text;
        int textLength; //longitud de texto original

        //Se crea la tabla de prefijos
        vector<unsigned> kmpPreProcessTable(const string& pattern);

    public:
        KnuthMorrisPratt(const string& text);
        unsigned countMatches(const string& pattern);

};

#endif