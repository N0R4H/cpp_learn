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
	for (int _ = 0; _<l; ++_){
		for (int r =0; r<l; ++r){
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

static void transpose(std::vector<std::vector<float>>& v){

		int rows = v.size();
		int cols = v[0].size();

		std::vector<std::vector<float> > L;
		std::vector<float> A;

		for (int i = 0; i<rows; ++i){
			 for (int j = 0; j< cols; ++j){
			 	A.push_back(v[j][i]);
			 }
			L.push_back(A);
			A = {};
		}

		cout<<"transpose is,"<<endl;
		for (int i = 0; i<rows; ++i){
			 for (int j = 0; j< cols; ++j){
			 	cout<<L[i][j];
			 	cout<<", ";
			 }
			 cout<<endl;
		}

}


int main(){

	std::vector<std::vector<float>> A = {{4.0, 0.0, 0.0}, 
										 {2.0, 3.0, 0.0}, 
										 {1.0, 0.0, 0.0}};
	transpose(A);
	gram_matrix(A);
	return 0;
}

