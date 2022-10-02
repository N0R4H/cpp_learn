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



private:
  int hidden_number;
  string hidden_str;

 // hidden_number = 69;
  //hidden_str = "Secret";

protected:
  int protected_number=32;

  void show(){
    cout<<hidden_str;
  }

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

//             geom             (superclass)
//    __________|__________
//    |         |         |
//  circle rectangle triangle   (subclasses)

class geom{

private:
  int secret;

protected:
  float radius, length, breadth, l1, l2, l3;


public:

  void setradius(float r){
    radius = r;
    secret = 0;
  }

  void setlenbred(float l, float b){
    length = l;
    breadth = b;
    secret = 4;
  }

  void settria(float a, float b, float c){
    l1 = a;
    l2 = b;
    l3 = c;
    secret = 3;

  }

  void showsecret(){                  
    cout<<"secret is,"<<secret<<endl;
  }

};

class circle: public geom{
    
    public:
      void show(){
        cout<<"radius is, "<<radius<<endl;
      }

};

class rectangle: public geom{

public:
      void show(){
        cout<<"length is, "<<length<<"breadth is, "<<breadth<<endl;
      }
};

class triangle: public geom{
public:
  void show(){
    cout<<"The sides are, "<<l1<<l2<<l3<<endl;
  }


};


class Overload{

public:
  int cnt = 4;

void operator++ (){ //prefix increment
  cout<<"Used ++ as prefix"<<endl;
  ++cnt;
}

void operator++ (int){ //suffix increment
  cout<<"Used ++ as suffix"<<endl;
  cnt++;
}

Overload *operator+(int a){
  
  this->cnt = this->cnt+a; //"this" points to current member 
  return this;
}

};

int* ptrs(){
  int p;
  p = 23;
  cout<<p<<", "<<&p<<endl;

  int* a;
  a = &p;
  cout<<*a<<", "<<a<<endl;
  return a;
  
}

//SINGLETON class prevents more than one instantance of a class.
//This is mainly used, so that one can work on only one instance, rather than creating many.
//On top of that, tracking multiple instances, or destroying them for that 
//matter becomes tedious. Handling multiple instances of a class, could prove
//to be detrimental, since improper handling could result to memory leaks and
//crashes.

class SINGLETON{

private:
SINGLETON(); //CONSTRUCTOR Declaration
~SINGLETON(); //DESTRUCTOR Declaration
public:
  static SINGLETON* GetInstance();
  void DeleteInstance();

};

SINGLETON::~SINGLETON(){
  cout << "INSTANCE DELETED";
}

SINGLETON::SINGLETON(){
  cout << "INSTANCE CREATED";
}

static SINGLETON* singptr = NULL; //global static ptr which can be accessed throughout the program

SINGLETON* SINGLETON::GetInstance(){
  if (singptr == NULL)
        singptr = new SINGLETON();
  return singptr;
}

void SINGLETON::DeleteInstance(){
  if (singptr!=NULL)
        delete singptr;   //this will invoke the destructor
}


int main(){

#if 0
  int *pr;
  pr = ptrs();
  cout<<*pr<<endl;


  ABC obj1;                                 //creating object (obj1) of type class ABC
  ABC obj2;  
  ABC obj3(1,"different way of intializing");              //different way of creating an object
  

  //=============================OVERLOADING==========================================
  // OVERLOADING means something which has many meanings or implemented in different ways
  //OVERLOADING is a feature of OOP by which we can create one or more objects/functions.
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

  //Operator overloading
  //An operator which can do different tasks is overloaded
  //Overloaded operators are functions with special names: 
  //the keyword "operator" followed by the symbol for the operator being defined.
  //datatype operator {symbol} (args)

  Overload o;
  cout<<o.cnt<<endl;
  ++o;
  cout<<o.cnt<<endl;
  o++;
  cout<<o.cnt<<endl;
  Overload* h;

  h = o+43; //adding cnt member of o with 5 and storing it as cnt
  cout<<(*h).cnt<<h<<endl;
  cout<<o.cnt<<endl;
  

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
  
  son obj8; 

  cout<<obj8.show()<<endl;  //using protected subclass member function to show superclass data
  obj8.setdata(45);//using protected subclass member function to change superclass data
  cout<<obj8.show()<<endl;

  circle a;         //subclass circle derived from super class geom

  a.setradius(43);  //
  a.show();         //cannot use cout<<a.radius, since member is protected!!!


  rectangle b;        //subclass rectangle derived from super class geom
  b.setlenbred(10,12);
  b.show();         //cannot use cout<<b.length<<b.breadth, since member is protected!!!

  b.showsecret();   //show private data
  //

  triangle c;
  c.settria(1,2,3);
  c.show();
  c.showsecret();
#endif
  SINGLETON* sptr = SINGLETON::GetInstance();
  sptr->DeleteInstance();

  
}