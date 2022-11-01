#ifndef KMP
#define KMP

#include <vector>
#include <string>

using namespace std;

class KnuthMorrisPratt{
    private:
        string text;
        string pattern;
        vector<unsigned> table; //tabla de prefijos 
        int patternLength; //Longitud de patron
        int textLength; //longitud de texto original

        //Se crea la tabla de prefijos
        void kmpPreProcess();

    public:
        KnuthMorrisPratt(const string& text,const string& pattern);
        unsigned countMatches();

};

#endif