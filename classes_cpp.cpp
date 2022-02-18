#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;


class ABC{
  public:
      int number;
      string str;

}


int main(){
  ABC obj1;

  obj1.number = 45;
  obj1.str = "type ABC obj1"

  ABC obj2;

  obj2.number = 24;
  obj2.str = "type ABC obj2"

  cout<<obj1.number + obj2.number<<endl;

  	

}