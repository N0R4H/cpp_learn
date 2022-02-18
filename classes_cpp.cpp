#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;



class ABC{          // class name
  public:           // access identifier
      int number;   // integer attribute
      string str;   // string attribute

  ABC(){
    number = 1;
    str = "constructor"
  }

};


int main(){
  ABC obj1;       //creating object (obj1) of type class ABC

  obj1.number = 45;           //setting integer attribute  of obj1
  obj1.str = "type ABC obj1"; //setting string  attribute  of obj1

  ABC obj2;     //creating object (obj2) of type class ABC

  obj2.number = 24;           //setting integer attribute  of obj1
  obj2.str = "type ABC obj2"; //setting string  attribute  of obj1
  cout<<obj1.number+obj2.number<<endl;
}