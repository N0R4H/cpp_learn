#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>


using namespace std;


string bin(int a){
   return a==0?"":a&1?bin(a>>1).append("1"):bin(a>>1).append("0"); 
}

string addition(string a, string b){
   string res = "";
   unsigned int carry  = 0;
   int l;
   reverse(a.begin(), a.end());
   reverse(b.begin(), b.end());
   if (b.length()  >= a.length() ){
      l = a.length();
      swap(a, b);

   }
   else{

      l = b.length();
   }
   for (int i =0; i<a.length(); ++i){
       if (i < l){
          int add =  ((int)b[i]-48 )+((int)a[i] - 48) + carry;
          int digit = add%10;
          carry = add/10;
          res+=(char)(digit+48);
          
       }
       else{
          int add =   ((int)a[i] - 48) + carry;
          int digit = add%10;
          carry = add/10;
          res+=(char)(digit+48);
       }
   }
   if (carry > 0){
      res+=(char)(carry+48);
   }
   
   reverse(res.begin(), res.end());
   return res;
}

string multiplication(string a, string b){
   string res, ans, param1, param2;
   unsigned int carry;
   int c = -1;
   string sign = "";
   std::vector<string> p;

   if (a[0] == '-'){
      if (b[0] !='-'){
         sign = "-";
      }
      else{
         a = a.substr(1,-1);
         b = b.substr(1,-1);
      }
   }
   if (b[0] == '-'){
      sign = "-";
      b = b.substr(1,-1);
   }

 for (int d1 = b.length()-1; d1 > -1; d1--){

   carry = 0;
   c+=1;
   res = "";
   for (int _ = 0; _< c; ++_){
      res+='0';
   }
   for (int d2 = a.length()-1; d2 > -1; d2--){
      
         int mul =  ((int)b[d1]-48 )*((int)a[d2] - 48) + carry;
         int digit = mul%10;
         carry = mul/10;
         res+=(char)(digit+48);

      }
      if (carry > 0){
         res+=(char)(carry+48);
      }
      reverse(res.begin(), res.end());
      p.push_back(res);
   }

   if (p.size() >=2){
      param1 = p.back();
      p.pop_back();
      param2 = p.back();
      p.pop_back();

      ans = addition(param1, param2);

   }
   else{
      ans = "0";
   }
   while (p.size() >=1){
      param1 = p.back();
      p.pop_back();
      ans = addition(param1, ans);
   }

   ans.erase(0, ans.find_first_not_of('0'));
   if (ans == ""){
      return "0";
   }
   sign+=ans;
   return sign;
 }


void abc(int (&a)[3]){
   
   for (int i = 0; i < 3; ++i){
      a[i]+=3;
   }
   
}


int main(){
   // string res = "";
   // int carry  = 2;
   // char a = '9';
   // char b = '1';
   // int mul = ((int)a-48 )*((int)b - 48) + carry;
   // carry = mul/10;
   // int digit = mul%10;

   // res+=(char)(digit+48);
   // cout<<res;
  //  string a= "asdasds";
  //  std::vector<string> v;
  //  v.push_back(a);

  // reverse(a.begin(), a.end());
  // cout<<a<<endl;
   //string b = multiplication("1234", "3");
   // std::vector<string> v {"123","abc"};
   // string b = v.back();
   // cout<<b<<endl;
   //cout<<multiplication("01", "0");
   int arr[3] = {1, 2, 3};
   abc(arr);
   for (int i = 0; i < 3; ++i){
      cout<<arr[i]<<endl;
   }
}