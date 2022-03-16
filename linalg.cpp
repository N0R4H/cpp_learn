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
	if (v.size() == 1){
		return v[0][0];
	}

	else if (v.size() == 2){
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

static void trace(std::vector<std::vector<float>>& v){
		if (v.size() != v[0].size()){
			cout<<"Not square matrix"<<endl;
		}
		else{
			float res = 0.0;
			for (int i = 0; i< v.size(); ++i){
				res+=v[i][i];
			}
			cout<<"Trace of matrix is,"<<res<<endl;

		}


}
static void covariance(std::vector<std::vector<float>>& v){
	if (v.size() != v[0].size()){
			cout<<"Not square matrix"<<endl;
		}
	std::vector<float> means;	
	for(int i = 0; i < v.size(); ++i ){
		float r = 0.0;
		for (auto j:v[i]){
			r+=j;
		}
		means.push_back(r/v.size());
	}
	std::vector<float> variance;
	for (int i = 0; i < v.size(); ++i ){
		float r = 0.0;
		for (int j = 0; j<v.size(); ++j){
			r+=(v[i][j] - means[i])*(v[i][j] - means[i])
		}
		variance.push_back(r/v.size())
	}
	//tbd



}


int main(){

	std::vector<std::vector<float>> A = {{2.0, 5.0, 3.0}, 
										{1.0, -2.0, -1.0}, 
										{1.0, 3.0, 4.0}};

	transpose(A);
	gram_matrix(A);
	cout<<determinant(A)<<endl;
	trace(A);
	covariance(A);
	return 0;
}

