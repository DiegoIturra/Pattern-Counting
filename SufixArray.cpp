#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string_view>
#include "SuffixArray.hpp"


using namespace std;

bool SuffixArray::compareSuffix(unsigned l,unsigned r){
    return _sv.substr(l) < _sv.substr(r);
}

SuffixArray::SuffixArray(const string& s){
    _t = s;
    _arr.resize(s.size() + 1);
    _t.push_back('$');
    _sv = string_view(_t);
    iota(_arr.begin(),_arr.end(),0);
    sort(_arr.begin(), _arr.end(), bind(&SuffixArray::compareSuffix,this,placeholders::_1, placeholders::_2));    
}

unsigned SuffixArray::countMatches(const string& s){
    // true si es que el string s no esta antes
    auto lower = lower_bound(_arr.begin(), _arr.end(),s,
                [this](unsigned l, const string &s) -> bool{
                return _sv.substr(l) < s;
    });

    // true si es que el string s no esta antes
    auto upper = upper_bound(_arr.begin(), _arr.end(), s,
                [this](const string &s,unsigned l ) -> bool{
                return _sv.substr(l,s.size()) > s;
    });
    
    return distance(lower,upper);
}
