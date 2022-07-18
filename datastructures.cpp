//---------------------------------------------CPP_LEARN--------------------------------------------------------//

//compile g++ -o cpplearn cpplearn.cpp
//run ./cpplearn
// or write a build file and ctrl + shift + b to build and ctrl + b to run 


#include <iostream>
#include <vector>   //include vectors
#include <list>     //include lists
#include <iterator> //include iterators
#include <map>      //include dictionary
#include <string>   //include strings
#include <deque>    //include deque
#include <any>      //any type
#include <cmath>    //math 
#include <limits>   //for limits for datatypes
using namespace std;


              void transform_vec(std::vector<int>& v){   //taking reference of args 
                int i=0;
                for (i=0;i<v.size();i++){
                  v[i]*=v[i];
                }

              }

              template<size_t N>                      // size of array must be known when referencing while compiling
              void transform_arr(int (&arr)[N]){      //taking reference of array with known size
                int i = 0;
                for (i=0;i<*(&arr+1)-arr;i++){
                   arr[i]*=2; 
                }

              }

              void transform_list(std::list<int>& l){
                list<int>::iterator it;                 //initializing iterator pointer               
                it = l.begin();                         //pointing to 1st element
                advance(it,3);                          //advance address by 3                 
                l.insert(it,200);                       //insert at that address
                for (it = l.begin();it!=l.end();it++){
                      *it*=2;
                }
              }

              void transform_dict(std::map<int ,char>& dict){
                dict.insert(make_pair(0,'l'));
              }

              void transform_str(char a[], int N){
                for (int i =0; i<N;i++){
                      a[i] = 'c';
                }
              }


int vectors()
{
          //vectors are  Data structures that are STRICTLY contiguous memory allocation.
          //not fixed size, occupy more space than array and more dynamic than array
          //supports random access

          //VECTORS ONLY USED WHEN FREQUENT INSERTION OR DELETION IS DONE!!! 

          std::vector<int> a = {1,2,3,4,5,6};// vector <type> vec = {..}
          for (auto& i:a){
                    cout<<i;
                }
          cout<<endl;

          transform_vec(a);
          int i;
          cout<<"{";
          for (i=0;i<a.size()-1;i++){     //vec.size() gives length of vector
            cout<<a[i]<<", ";
          }
          cout<<a[a.size()-1];
          cout<<"}"<<endl;

          cout<<(&a+1)<<endl;
          std::vector<vector<int>> v = {{}};
          v.push_back({1,2,3,4});
          v.clear();
          return 0;
}


int arrays()
{
        //ARRAY
          //Arrays are Data structures that are STRICTLY contiguous memory allocation.
          //fixed size, occupy less space than vector
          //supports random access

          //ARRAYS ONLY USED WHEN FREQUENT ACCESS IS DONE!.
          // type arr[] = {...};
          // arr is a (type*) ptr which points to the FIRST element of the arr
          // &arr is a (type array*) which points to ALL elements of the arr
          // (&arr+1) will point to the NEXT array of N elements
          //*(&arr + 1) will point to the first element of the NEXT array
          //*(&arr  + 1) - arr  will give size of array!
          int i;
          int arr[] = {1,2,4,5}, len = *(&arr+1)-arr-1;   //type array[size] = {..}
          for (i=0;i<*(&arr+1)-arr;i++){                  
            cout<<arr[i];
          }
          cout<<endl;
          
          transform_arr(arr); //passing value
          
          cout<<"{ ";
          for (i=0;i<len;i++){
            cout<<arr[i]<<", ";

          }
          for(auto k: arr){
            cout<<k<<endl;
          }
          cout<<arr[len]<<"}";
          cout<<endl;
          cout<<*(&arr+1)-arr;
          cout<<endl;

//ARRAY
}

int lists(){
              //Lists are Data structures that allow non-contiguous memory allocation.
              //unlike python, list does not have "random access []", BUT HAS ITERATOR PTR 
              //double linked

              //unlike array, vector; lists are not contiguous.

              //LISTS ONLY USED WHEN THE DATA IS VERY LARGE FOR INSERTION OR DELETION 
              std::list<int> l = {1,2,3,4,5,6};
              list<int>::iterator ptr;      //iterator pointer
              for (auto& i:l){
                cout<<i;
              }
              cout<<endl;
              transform_list(l);
              cout<<"{ ";
              for (ptr = l.begin();ptr != l.end();ptr++) {
                cout<<*ptr<<", ";             //dereferencing the iterator 
              }
              ptr++;
              cout<<*ptr<<"}"<<endl;

return 0;
}

int dicts(){
              //Map or dictionary is a datastructure consisting of key-value pair
              //Map can randomly access any value by using the key
              string op = "";
              map <int,char> dict = {{1,'a'},{2,'a'},{3,'c'}};
              cout<<"{";
              for (auto& [k,v]:dict){
                cout<<k<<":"<<v<<", ";
              }
              cout<<"}"<<endl;
              transform_dict(dict);
              cout<<"{";
              for (auto& [k,v]:dict){
                cout<<k<<":"<<v<<", ";
              }
              cout<<"}";

              map<string,int> h = {{"ab",4},{"a",2},{"b",5}};
              op+="a";
              op+="b";
              cout<<h[op]<<endl;
              //searching for an unknown key in a dict will make it KNOWN
              //and give it garbage value.
              return 0;
}

int strings(){
  //STRINGS
  //STRINGS ARE AN "CONST" ARRAY OF  CHARACTERS
  string j = "asdas";       
  const char* k = "asdas";       
  char a[] = "abc";       // a = "abc\0"; length = 2 including the null
  for (int i=0;i<*(&a+1)-a-1;i++){  //&a --> complete string address, a --> first character address; -1 is used for excluding null \0 
      printf("%c",a[i]);
   }
   transform_str(a,*(&a+1)-a-1);
   for (int i=0;i<*(&a+1)-a-1;i++){
      printf("%c",a[i]);
   }

  return 0; 
}

bool check(int* f){
  return *f==1?true:false;
}

std::string reverse_words(const std::string& str) {
    string res = "",a = "";
    deque <string> con =  {};
    for (char c:str){
      if (c == ' '){con.push_front(a);a = "";}   
      else{a+=c;}
    }
   con.push_front(a);
   for (int i = 0; i<con.size()-1; ++i){res+=con[i];res+=" ";}
  res+=con[con.size()-1];
  return res;  
}


int max(std::vector<int> v){
  if (v.size()<=1){
      return v.size()?v[0]:0;
  }
  int max = v[0];
  for (int i = 1; i<v.size(); ++i){
        if (max < v[i]){
          max = v[i];
        }
  }
  return max;

}

string bin(int a){
   return a==0?"":a&1?bin(a>>1).append("1"):bin(a>>1).append("0"); 
}

static void integer_square_root(string n) {
    map <int,int> hash_map = {};
    for (unsigned long i = 0;i<n.size(); ++i){
      hash_map[~i+n.size()] = (int)n[i] - 48;
  } 
  for (auto& [k,v]:hash_map){
    cout<<k<<"->"<<v<<endl;
  }

}



// std::string factorial(int f){
//   if (f==0){
//     return 1;
//   }
//   map <int,int> l = {};
//   map <int,int> ans = {}
//   return "as";
// }


int main(){
    // vectors();
    // arrays();
    // lists();
    // dicts();
    // string a = "Hello World!";
    //cout<<max({6})<<endl;
    cout<<bin(1231)<<endl;
    return 0;

}

