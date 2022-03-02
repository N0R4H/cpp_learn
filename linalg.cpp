#include <iostream>
#include <cmath>
#include <vector>
#include <string>

using namespace std;


// G = A.A.t
static void gram_matrix(std::vector<std::vector<float>>& A){

	if (A[0].size() != A.size()){	//FOR NOW ONLY SQUARE MATRICES
		cout<<"Error";
	}
	else{
	
	int l = A.size();
	std::vector<std::vector<float>> L;
	std::vector<float> v;

	for (int i = 0; i<l; ++i){
		for (int j = 0; j<l; ++j){
			v.push_back(0.);
		}
		L.push_back(v);
		v = {};

	}

	for (int i = 0; i<l; ++i){
		for (int j = 0; j<l; ++j){

			cout<<A[i][j];
			cout<<", ";
		}
		cout<<endl;
	}
	int res = 0;
	for (int _ = 0; _<3; ++_){
		for (int r =0; r<3; ++r){
			for (int c = 0; c<3; ++c){
				res+=A[_][c]*A[r][c];
			}
			L[_][r] = res;
			res = 0;
		}

	}
	cout<<"Gramian matrix is,"<<endl;
	for (int i = 0; i<3; ++i){
		for (int j = 0; j<3; ++j){
			cout<<L[i][j];
			cout<<", ";
		}
		cout<<endl;
	}
}
}

int main(){

	std::vector<std::vector<float>> A = {{4.0, 0.0, 0.0}, 
										 {2.0, 3.0, 0.0}, 
										 {1.0, 0.0, 0.0}};
	gram_matrix(A);

	return 0;
}


