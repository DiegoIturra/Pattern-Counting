#include <iostream>
#include "KMP.hpp"

using namespace std;

int main(){

	KnuthMorrisPratt kmp("holahola","hola");
	cout << "matches: " << kmp.countMatches() << endl;

	return 0;
}