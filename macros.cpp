#include <iostream>
using namespace std;

/**
 * MACROS ARE MERELY TEXT REPLACEMENTS OF THE CODE, WHICH
 * IS DONE ESPECIALLY FOR PREPROCESSING. 
*/
#define mul(x,y) x*y
#define add(x,y) x+y
#define sub(x,y) x-y
#define div(x,y) x/y


/*
*INLINE FUNCTION CUTS DOWN ANY LINKER OVERHEAD, AS IF 
*THERE ISN'T ANY FUNCTION CALL, THIS IS DONE FOR OPTIMIZATION
*ALTHOUGH SOME FUNCTIONS CANNOT BE COMPLETELY INLINED, ESPECIALLY
*THE RECURSIVE ONES. HOWVER THEY ARE INLINED ONLY TO A CERTAIN 
*EXTENT. 
*/
inline static const char* bin(int _){
	const char* ans = !_?"0b":bin(_>>1)+(_&1?'1':'0');
	return ans;
}

int main(){
	cout<<bin(2);
}