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
float determinant(std::vector<std::vector<float>>& v){

	if (v.size() == 2){
		return v[0][0]*v[1][1] - v[0][1]*v[1][0];
	}

	else{
		
		int length = v.size();
		float result = 0.0;
		for (int i = 0; i < length; ++i){
			std::vector<std::vector<float>> L;
			for (int row = 1; row < length; ++row){
				 std::vector<float> a;
				 for (int col = 0; col < length; ++col){
				 		if (col!=i){
				 			a.push_back(v[row][col]);
				 			}
				} 
				if (a.size()>0){
					L.push_back(a);
				}
			}
			result+=pow(-1, i&1)*v[0][i]*determinant(L);
		}
	return result;
	}
	
}



int main(){

	std::vector<std::vector<float>> A = {{3.0, 7.0, 1.0}, 
										{-5.0, 0.0, 4.0}, 
										{1.0, 32.0, -5.0}};

	transpose(A);
	gram_matrix(A);
	cout<<determinant(A)<<endl;
	return 0;
}

