#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;



class ABC{          // class name

  private:
      int hidden_number;
      string hidden_str;

      void privatefn(){
        cout<<"this a private member function";
      }

  public:           // public access modifier
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
  ~ABC(){
    //cout<<"Destructor invoked"; //destructor destroys the object created
    
  }

};


class CDE{

protected:
  int protected_number=32;

private:
  int hidden_number;
  string hidden_str;

 // hidden_number = 69;
  //hidden_str = "Secret";

public:
  int number;
  string str;

  void setdata(){
      hidden_number = 21;     //only member functions can access private attributes
      hidden_str = "hidden";
  }

  void getdata(){
      cout<<"Number and string are:"<<number<<", "<<str<<endl;
      cout<<"HIDDEN Number and string are:"<<hidden_number<<", "<<hidden_str<<endl;
  };

  int num(){
    return hidden_number;
  }

};


class daughter: public CDE//daughter inheriting CDE with a public access specification
{

public:

  void setdata(int a){
    protected_number = a;
  }

  int show(){
    return protected_number;
  }

};

class son: protected CDE{ //son inheriting CDE with a protected access specification

public:
  void setdata(int a){
    protected_number = a;

  }
  int  show(){
    return protected_number;
  }


};



int main(){



  ABC obj1;                                 //creating object (obj1) of type class ABC
  ABC obj2;  
  ABC obj3(1,"different way of intializing");              //different way of creating an object
  

  //=============================OVERLOADING==========================================
  // OVERLOADING is a feature of OOP by which we can create one or more objects/functions.
  // C++ tries to find the EXACT function/constructor name with EXACT parameter types
  // Hence we can have 2 different constructors/functions with same name but different parameter types

  //obj1 = ABC(23,97);       //creating object (obj1) of 
                          //type class ABC  using constructor of EXACT attribute type.

  cout<<obj1.str<<" "<<obj1.number<<endl;   //changing default to custom attributes 

  //obj2 = ABC(3,"parameterized constructor");//creating object (obj1) of 
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

  //==================Access identifiers===============================================
  // There are 3 access identifiers:
  //public, private and protected.

  //PUBLIC:    Members under this can be accessed from ANYWHERE.
  //PRIVATE:   Members under this can be accessed only by MEMBER FUNCTIONS.
  //PROTECTED: Members under this can be accessed by only a MEMBER FUNCTION OF DERIVED CLASS.
  
  //-----------------Public--------------------
  CDE obj6;

  obj6.number = 43;     //setting public member
  obj6.str = "hello";   //setting public member
  //-----------------Private-------------------
  obj6.setdata();           //setting of private member using member function
  
  obj6.getdata();
  cout<<obj6.num()<<endl;
  //----------------Protected-----------------
  daughter obj7;
  cout<<obj7.show()<<endl;  //show protected member using member function of derived class
  obj7.setdata(65);         //using member function of derived class to set protected data
  cout<<obj7.show()<<endl;  
  //------------------------------------------

  //===========================Inhertiance========================================================
  //The ability of a class to derive characteristics from another, is called Inheritance.
  //Super class (parent)
  //        |   
  //        |
  //        V 
  //Sub class (child)
  //class child: {access specifier} parent
  //if access specifier is:
  //                        public: no change
  //                        protected:  public -> protected
  //                        private:    public -> private, public -> private
  // Private members of a base class can only be accessed by base member functions
  
  son obj8; //

  cout<<obj8.show()<<endl;  //using protected subclass member function to show superclass data
  obj8.setdata(45);//using protected subclass member function to change superclass data
  cout<<obj8.show()<<endl;


}