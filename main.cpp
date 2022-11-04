#include <iostream>
#include "KMP.hpp"
#include "SuffixArray.hpp"

using namespace std;

int main(){

	KnuthMorrisPratt kmp("hola diego iturra diego diegodiego");
	cout << "matches KMP: " << kmp.countMatches("diego") << endl;

	SuffixArray sa("Hello world my name is Jerry");
	cout << "matches SA: " << sa.countMatches("world") << endl;

	return 0;
}