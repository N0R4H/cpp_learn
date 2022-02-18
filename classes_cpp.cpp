#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;


int _(const std::string& a){
	int i = 0, j = 0;
    unsigned l1 = a.size();
    for (unsigned k = a.size()-1;k < -1; --k){
      i+=((int)a[k]-48)*pow(10,l1+~(int)k);
    }
    return i;
}



string sum_str(const std::string& a, const std::string& b) {
    return to_string(_(a) + _(b));
}




int main(){

	cout<<sum_str("123","345")<<endl;
  int a = 5

}