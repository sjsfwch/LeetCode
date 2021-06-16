#include "headers.h"
using namespace std;

#define max(a,b) (((a)>(b))?(a):(b))

int string2int(string s){
    int res=0;
    for (int i=0;i<s.size();i++){
        res*=10;
        res+=s[i]-'0';
    }
    return res;
}

