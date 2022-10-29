#include <iostream>
#include <string>
using namespace std;

/**
 * MACROS ARE MERELY TEXT REPLACEMENTS OF THE CODE, WHICH
 * IS DONE ESPECIALLY FOR PREPROCESSING. 
*/
#define mul(x,y) x*y
#define add(x,y) x+y
#define sub(x,y) x-y
#define div(x,y) x/y

#ifndef magic
#define magic !_?"0b": bin(_>>1) + (_&1?'1':'0')
#endif

/*
*INLINE FUNCTION CUTS DOWN ANY LINKER OVERHEAD, AS IF 
*THERE ISN'T ANY FUNCTION CALL, THIS IS DONE FOR OPTIMIZATION
*ALTHOUGH SOME FUNCTIONS CANNOT BE COMPLETELY INLINED, ESPECIALLY
*THE RECURSIVE ONES. HOWVER THEY ARE INLINED ONLY TO A CERTAIN 
*EXTENT. 
*/

inline static string bin(int _){
	string ans = magic;
	return ans;
}
int main(){
	cout<<bin(23124);
}