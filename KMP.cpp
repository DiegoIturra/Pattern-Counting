#include "KMP.hpp"
#include <vector>
#include <string_view>
#include <string>

using namespace std;


vector<unsigned> KnuthMorrisPratt::kmpPreProcessTable(const string& pattern){
    unsigned patternLength = pattern.length();
    vector<unsigned> table(pattern.length(),0);
    int i = 0;
    int j = -1;
    table[0] = -1;

    //se recorre el patron a buscar y se actualiza la tabla de prefijos cuando
    //hay un mismatch
    while(i < patternLength){
        while(j >= 0 && pattern[i] != pattern[j]){
            j = table[j];
        }
        i++; j++;
        table[i] = j;
    }
    return table;
}


KnuthMorrisPratt::KnuthMorrisPratt(const string& text){
    this->text = text;
    this->textLength = text.length();
}


unsigned KnuthMorrisPratt::countMatches(const string& pattern){
    unsigned patternLength = pattern.length();
    vector<unsigned> table = kmpPreProcessTable(pattern);

    int i = 0, j = 0;
    unsigned matches = 0;

    while(i < this->textLength){

        //cada vez que hay un mismatch se actualizan los indices de j para seguir
        //haciendo shift sobre el texto original
        while(j >= 0 && this->text[i] != pattern[j]){
            j = table[j];
        }
        i++; j++;

        //Cada vez que el valor de j alcanza el tamaño del patron es porque
        //hay un match
        if(j == patternLength){
            matches++;
            j = table[j];
        }
    }
    return matches;
}