#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <bits/stdc++.h>

using namespace std;


typedef struct{
	int age;
	string name;
}MYSTRUCT; 

int main(){

	MYSTRUCT ob;
	ob.age = 23;
	ob.name = "ROHAN";

	cout<<ob.name;
}