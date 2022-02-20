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

  //parameterized constructor (same name but different parameter type)
  ABC(float p1, float p2){
    number = p1;
    str = p2;
  };

  //copy constructor
  ABC(ABC &obj){
    number = obj.number;
    str    = obj.str;

  };


};

int main(){



  ABC obj1;                                 //creating object (obj1) of type class ABC
  ABC obj2;  
  ABC obj3(1,"different way of intializing");              //different way of creating an object
  

  //=============================OVERLOADING==========================================
  // OVERLOADING is a feature of OOP by which we can create one or more objects/functions.
  // C++ tries to find the EXACT function/constructor name with EXACT parameter types
  // Hence we can have 2 different constructors/functions with same name but different parameter types

  obj1 = ABC(2,97);       //creating object (obj1) of 
                          //type class ABC  using constructor of EXACT attribute type.

  cout<<obj1.str<<" "<<obj1.number<<endl;   //changing default to custom attributes 

  obj2 = ABC(3,"parameterized constructor");//creating object (obj1) of 
                          //type class ABC  using constructor of EXACT attribute type.

  cout<<obj2.str<<" "<<obj2.number<<endl;  //changing default to custom attributes 

  obj1.number = 45;           //setting integer attribute  of obj1
  obj1.str = "type ABC obj1"; //setting string  attribute  of obj1


  obj2.number = 24;           //setting integer attribute  of obj1
  obj2.str = "type ABC obj2"; //setting string  attribute  of obj1
  
  cout<<obj1.number+obj2.number<<endl;

  ABC obj4(obj3);     //shallow copy of obj3 contents to obj4 

  cout<<obj4.number<<"and"<<obj3.number<<endl;

  //===================================================================================

  
}