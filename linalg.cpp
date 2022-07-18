#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <Eigen/Dense>		//g++ -I /path/to/eigen/ my_program.cpp -o my_program 


using namespace std;
using namespace Eigen;



// G = A.A.t
static void gram_matrix(std::vector<std::vector<float>> A){

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

static void transpose(std::vector<std::vector<float>> v){

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
float determinant(std::vector<std::vector<float>> v){
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

static void trace(std::vector<std::vector<float>> v){
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
static void covariance(std::vector<std::vector<float>> v){

	//Cov(X) = (X-xm).T x (X-xm)

	std::vector<float> means;	
	for(int col = 0; col < v.size(); ++col ){
		float r = 0.0;
		for (int row = 0; row< v[0].size(); ++row){
			r+=v[row][col];
		}
		means.push_back(r/v.size());
	}
	for(int col = 0; col < v.size(); ++col ){
		float r = 0.0;
		for (int row = 0; row< v[0].size(); ++row){
			v[row][col]-=means[col];
		}	
	}
	cout<<"Deviations are,.."<<endl;
	for(int col = 0; col < v.size(); ++col ){
		float r = 0.0;
		for (int row = 0; row< v[0].size(); ++row){
			cout<<v[col][row]<<", ";
		}
		cout<<endl;
		
	}
	std::vector<std::vector<float>> res;
	for (int k = 0; k < v.size(); ++k){
		std::vector<float> l;
		for(int col = 0; col < v.size(); ++col ){
			float r = 0.0;
			for (int row = 0; row< v[0].size(); ++row){
					r+=v[row][k]*v[row][col];
			}
			r = r/v.size();
			l.push_back(r);
	}
	res.push_back(l);

}
	cout<<"covariance are,.."<<endl;
	for(int col = 0; col < v.size(); ++col ){
		for (int row = 0; row< v[0].size(); ++row){
			cout<<res[col][row]<<", ";
		}
		cout<<endl;
		
	}
    

}


int main(){
	srand(time(0));	//set seed for pseudorandom nos.

	std::vector<std::vector<float>> A = {{2.0, 5.0, 3.0}, 
										{1.0, -2.0, -1.0}, 
										{1.0, 3.0, 4.0}};


	std::vector<std::vector<float>> B = {{1,2},{2,3}};

	transpose(A);
	gram_matrix(A);
	cout<<determinant(A)<<endl;
	trace(A);
	covariance(B);
	//using eigen package instead of reinventing the wheel

	//EIGEN

	//explicit type declaration matrix
	//Matrix<typename_scalar, 
	//		int RowsAtCompileTime, 
	//		int ColsAtCompileTime, 
	// 		int Options = 0,
    //		int MaxRowsAtCompileTime = RowsAtCompileTime,
    //		int MaxColsAtCompileTime = ColsAtCompileTime>

	
    Matrix <float, 2,2> identity;
    identity(0,0) = 1; identity(0,1) = 0;
    identity(1,0)= 0;  identity(1,1) = 1;
    cout<<"2X2 identity matrix is, "<<identity<<endl;

    //constructor matrix
    // typedef Matrix<float, Dynamic, Dynamic> MatrixXf   (MatrixXF is of type Matrix, float, dynamic, dynamic)
    // Matrix.shape = (N, M)
    //MatrixXf m;      m is constructor of dynamic float matrix
    // Matrix3f n;     n is constructor of 3x3 float matrix

	 Matrix3f m(3,3);

	  for (int i = 0; i<3; ++i){
	  	for (int j = 0; j<3; ++j){
	  			m(i,j) = 3.0;
	  	}
	  }
	  
	  Matrix3f a(3,3);

	  for (int i = 0; i<3; ++i){
	  	for (int j = 0; j<3; ++j){
	  			a(i,j) = 2.0;
	  	}
	  }
	  cout<<a+m<<endl;	//matrix addition

	  cout<<a*m<<endl; //matrix multiplication (dot)


	  MatrixXd b(5,3);	
	  for (int i = 0; i<5; ++i){
	  	for (int j = 0; j<3; ++j){
	  			b(i,j) = pow(-1, i)*2.0;
	  	}
	  }
	  cout<<b<<endl;

	  MatrixXd d(3,2);
	  for (int i = 0; i<3; ++i){
	  	for (int j = 0; j<2; ++j){
	  			d(i,j) = 4.0;
	  	}
	  }
	  cout<<d<<endl;      
	  cout<<b*d<<endl;  //5x3 dot 3x2 == 5x2

	  cout<<"-------------"<<endl;
	  cout<<b<<endl;            //5x3
	  b.resize(3, 5);           //reshape to 3x5
	  cout<<"-------------"<<endl;
	  cout<<b<<endl;            //3x5

	  //Vectors;
	  //typedef Matrix<float, dynamic, 1> VectorXf
	  //Vector.shape = (N, 1)

	  typedef Matrix <float, 10,1> myvec;
	  myvec t;

	  //Comma initialization syntax
	  t<<1,2,3,4,5,6,7,8,9,10;
	  cout<<t<<endl;

	  //transpose, conjugate and adjoint  of a vector/matrix

	
	  Matrix<float, 4, 4> mymat;
	  mymat<< 3,-0, 5, -8, 6,1,2, -7, 6, 0, -6, -6, 2, 4, 5, 6;
	  //only applicable for NXN matrices
	  cout<<"mymat is "<<mymat<<endl;
	  cout<<"-----------------"<<endl; 

	  cout<<"transpose of mymat is "<<mymat.transpose()<<endl;

	  cout<<"-----------------"<<endl; 
	  cout<<"conjugate of mymat is "<<mymat.conjugate()<<endl;

	  cout<<"-----------------"<<endl; 
	  cout<<"adjoint mymat is "<<mymat.adjoint()<<endl;

	  cout<<mymat<<endl;

	 

	

	return 0;
}

