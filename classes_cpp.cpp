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

  //default constructor
  ABC(){
    number = 1;
    str = "default constructor";
  };

  //parameterized constructor
  ABC(int p1, string p2){
    number = p1;
    str = p2;
  };



};


int main(){


  ABC obj1;                 //creating object (obj1) of type class ABC

  cout<<obj1.str<<" "<<obj1.number<<endl;   //default attribute
  
  obj1 = ABC(2,"parameterized constructor");  //creating object (obj1) of 
                                             //type class ABC with custom attributes

  cout<<obj1.str<<" "<<obj1.number<<endl;   //changing default to custom attributes 

  obj1.number = 45;           //setting integer attribute  of obj1
  obj1.str = "type ABC obj1"; //setting string  attribute  of obj1

  ABC obj2;                   //creating object (obj2) of type class ABC

  obj2.number = 24;           //setting integer attribute  of obj1
  obj2.str = "type ABC obj2"; //setting string  attribute  of obj1
  cout<<obj1.number+obj2.number<<endl;
}