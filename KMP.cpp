#include "KMP.hpp"
#include <vector>
#include <string_view>
#include <string>

using namespace std;

void KnuthMorrisPratt::kmpPreProcess(){
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
}

KnuthMorrisPratt::KnuthMorrisPratt(const string& text,const string& pattern){
    this->text = text;
    this->pattern = pattern;
    this->table.assign(pattern.length(),0);

    this->patternLength = pattern.length();
    this->textLength = text.length();

    kmpPreProcess();
}

unsigned KnuthMorrisPratt::countMatches(){

    int i = 0, j = 0;
    unsigned matches = 0;

    while(i < textLength){

        //cada vez que hay un mismatch se actualizan los indices de j para seguir
        //haciendo shift sobre el texto original
        while(j >= 0 && text[i] != pattern[j]){
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