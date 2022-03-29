#include <iostream>

using namespace std;


void intro_2_pointers(){

	int a = 5;   		// a is a variable with value 5 and an address
	cout<<&a<<endl;		// & is used as a prefix for showing the address of the variable
	cout<<*&a<<endl;	// * is used to dereference the address and show the value
	cout<<&*&a<<endl;	// similarly to show the address once again

	int* p; 			//p is a pointer, which will point at an address of a int value
	//float a = 32.5;		//declaring float variablr
	//p = &a; 			//ERROR, p is declared for pointing at an address of int not float!
	int b = 23;
	p = &b;				//p points at address of b
	cout<<"Address is "<<&b<<"value is "<<b<<endl; //using * to change pointer pointing to address to value

	++(*p);	//incrementing value by one, this will affect the value of the shared location

	cout<<"Address is "<<p<<"value is "<<*p<<endl; //using * to change pointer pointing to address to value

	*(p+1) = 27;		//shifting pointer to address by 1	and assigining another value

	cout<<*(&b+1)<<endl; // same as *(p+1)

	//cascadeing pointers
	
	int *p1;		//p1 is a pointer, which will point at an address of a int value
	int **p2;		//p2 is a pointer which points at an address of an address of a int value
	int ***p3;      //p3 is ''''' address of address of address of int value
	//int ***...pn  // pn is ''' address of address of ........ of int value
	//meaning that you will have to dereference pn 'n' times to get the value!
	
	p1 = &b;		//p1 points at address of b
	p2 = &p1;		//p2 points at address of address of b
	p3 = &p2;		// p3 '''' address of address of address of b
	//pn = &pn-1    //pn ''''

	cout<<*p1<<" same as "<<**p2<<endl;	//same as *****...pn
	
}

void arrays_and_pointers(){
	int arr[5] = {1,2,3,4,5}; //can assume an array as pointers in sequence

	cout<<"first element is "<<arr[0]<<" and its address is "<<arr<<endl; //array name is a pointer pointing to address of first element

	cout<<"third element is "<<*(arr+2)<<endl; //shifting pointer to 3rd position and dereferencing it

	//if array name points at first element of array,
	//then &array will point at the complete array
	//therefore array == *&array == &array[0]

	cout<<"length of array is "<<*(&arr + 1)-arr<<endl;

	//in the above line, &arr  points at the whole array,
	//by incrementing &arr by 1, we are shifting the whole 
	//array by its length, then if we dereference it, the pointer
	//points at the first element of another array, if we subtract
	// this from the array name, we get the length

	//Note: a pointer which has a certain length, will always
	//shift by that length
	//so int* p, can shift by 1;
	//while int(* p)[10], will shift by 10
	//Hence &arr shifts by its length 
	
	int cascade[2][3][2] = {{{1, 2}, 
							 {3, 5}, 
							 {5, 6}}, 

						    {{7, 8}, 
						     {9, 10}, 
						     {11, 12}}}; //array[]..[batch][rows][cols]
	//&cascade -> address of whole array
	//*&cascade == cascade -> address of {{1, 2}, {3, 5}, {5, 6}}
	//**&cascade == *cascade -> address of {1, 2}
	//***&cascade == **cascade -> address of 1
	//****&cascade == ***cascade -> 1
	cout<<****&cascade<<", "<<***cascade<<endl; // which is 1

	//we can also navigate through a cascaded array using pointers
	cout<<*(*(*(*&cascade + 1) + 1) + 1)<<" or "<<cascade[1][1][1]<<endl;

	int(* ptr)[3]; //pointer of length 3

	int arr3[10] = {1,2,3,4,5,6,7,8,9,0};

	//ptr = &arr3; // ERROR, pointer cannot point to more than its requirement; 3 != 10 
	//therefore lets create an array of pointers

	int* f[3] = {arr3, arr3+1, arr3+2};	//f is an array of int pointers

	**f = 5;			//**f == *f[0] dereferencing address element and changing value
	cout<<*arr3<<endl;	//arr3 = {5,2,3,4,5,6,7,8,9,0}

	**f = 1;

	cout<<f[2]<<"--"<<arr3+2<<endl;			//same address
	cout<<(f[2]+1)<<"--"<<(arr3+3)<<endl;	//same address
	cout<<(f[2]+1)<<"--"<<arr3+4<<endl;
	
	int* o;
	o =  *(*(&f + 1)-1); //shifting by 3 and pointing 
						//to the address of the address of  
						//first element, shifting down by 1,
						//dereferencing it further to point at 
						// the address of last element of f
	cout<<*o<<endl; 	//3
	cout<<*(o-1)<<endl;  //2
	cout<<*(o+1)<<endl;  //4 which can be accessed too!

	//Therefore we can access all the elements of 
	//an array, by having knoweledge of at least
	//few pointers  pointing at few elements of the array!
	for(unsigned i = 0; i < 10; ++i){
		cout<<*(o-2+i)<<" <---> "<<arr3[i]<<endl;
	}
}

void memory_management(){
	//MEMORY MANAGMENT
	//With help of pointers we can manually play around with the memory addresses
	//of variables, however that isn't all, we can also assign new or delete dynamic memory
	//to pointers of certain types.

	//new operator (allocates heap memory)
	//delete operator	(frees heap memory)


	//remember in the aforementioned activities, 
	//the pointers are pointing to stack memory not heap
	//therefore DO NOT DELETE them
	//eg:- 
	//int *ptr2;	//declaring pointer
	//*ptr2 = 23;	//pointing it to stack memory
	//delete ptr2 	//ERROR segmentation fault, core dumped kaboom!
	//instead:-

	int *ptr1;
	ptr1 = new int;	//allocated 8 bytes (64bit system) 

	*ptr1 = 10;  	// dynamically allocated
	cout<<*ptr1<<ptr1<<endl;
	delete ptr1;	//deleting memory

	cout<<*ptr1<<ptr1<<endl;//value is null, but pointer is still pointing to heap

	int *ptr2;
	ptr2 = new int[10];		//allocating heap array

	for (unsigned i = 0; i < 10; ++i){
		*(ptr2 + i) = i;
	}
	for (unsigned i = 0; i < 10; ++i){
		cout<<*(ptr2+i)<<"lies in address"<<ptr2+i<<endl;
		//each address excedes the previous one by 4 (int byte = 4)
	}
	
	delete[] ptr2;	//deallocate complete heap array
	cout<<endl<<endl;
	//always  remember to pair new with delete

	//Dynamic array of pointers
	int**abc;
	abc = new int* [5];


	for (int i = 0; i< 5; ++i){
		*(abc+i) = new int ;		//allocating for each pointer
		*(*(abc+i)) = i;
	}

	for (unsigned i = 0; i< 5; ++i){
		cout<<*(*(abc+i))<<"lies in address "<<*(abc+i)<<endl;
	}
	
	delete[] abc;

	//creating a dynamic array using new
	cout<<"CREATING DYNAMIC MATRIX USING NEW DELETE"<<endl;

	int** n;

	n = new int*[3]; // gives address of address of first element of array

	for (unsigned i = 0; i<3; ++i){
		*(n+i) = new int[3];	//gives address of first element
		for (unsigned j = 0; j<3; ++j){
			*(*(n+i)+j) = i*j;
		}
	}
	for (unsigned i = 0; i<3; ++i){
		for (unsigned j = 0; j<3; ++j){
			cout<<*(*(n+i)+j)<<", ";
		}
		cout<<endl;
	}

	for (unsigned i = 0; i<3; ++i){
		delete[] *(n+i);
	}
	delete[] n;


	cout<<"MALLOC AND FREE"<<endl;
	//MALLOC AND FREE functions
	//stands for Memory allocation
	//MALLOC -> allocates a BLOCK of memory
	

	//Allocates a chunk of memory, hence requires ONE argument
	//the values are unintialized

	int *mallptr;
	//malloc(N x sizeof(datatype)) returns  a void* which needs to be type casted using (datatype* )
	mallptr = (int* )malloc(3*sizeof(int)); //mallocs dynamic array of integers with size 3

	//if allocation is not possible, it will return a nullptr
	for (unsigned i = 0; i < 3; ++i ){
		*(mallptr+i) = i;
	}

	for (unsigned i = 0; i < 3; ++i ){
		cout<<*(mallptr+i)<<"lies in address "<<(mallptr+i)<<endl;
	}

	//free memory
	free(mallptr);
	cout<<endl<<endl;

	cout<<"CALLOC AND FREE"<<endl;
	//CALLOC and FREE Functions
	//stands for contiguous allocation
	//CALLOC -> allocates contiguous memory

	//Unlike malloc, calloc provides a DISCIPLINED form memory
	//All elements are intialized to 0
	//Requires 2 arguments

	float* callptr;
	callptr = (float* )calloc(10, sizeof(float));
	for (unsigned i = 0; i < 10; ++i ){
		cout<<*(callptr+i)<<", ";
	}
	cout<<endl;
	for (unsigned i = 0; i < 10; ++i ){
		*(callptr+i) = i; 
	}
	for (unsigned i = 0; i < 10; ++i ){
		cout<<*(callptr+i)<<" lies in address "<<callptr+i<<endl;
	}
	cout<<endl;
	//free memory
	free(callptr);
	
	//After freeing the pointer will STILL point at the address regardless of value occupancy

	cout<<"REALLOC AND FREE"<<endl;
	//REALLOC and free
	//stands for real allocation
	//REALLOC -> for dynamic sizing

	//changes pointer size which has been allocated either using malloc or calloc
	//requires 2 arguments
	mallptr  = (int* )realloc(mallptr, 6*sizeof(int)); // changing from 3 to 4


	for (unsigned i = 0; i < 6; ++i ){
		*(mallptr+i) = i;
	}

	for (unsigned i = 0; i < 6; ++i ){
		cout<<*(mallptr+i)<<"lies in address "<<(mallptr+i)<<endl;
	}


	free(mallptr);

	callptr = (float* )calloc(10, sizeof(float)); //changing from 10 to 3

	for (unsigned i = 0; i < 10; ++i ){
		cout<<*(callptr+i)<<", ";
	}
	cout<<endl;
	for (unsigned i = 0; i < 10; ++i ){
		*(callptr+i) = i; 
	}
	for (unsigned i = 0; i < 10; ++i ){
		cout<<*(callptr+i)<<" lies in address "<<callptr+i<<endl;
	}
	cout<<endl;
	//free memory
	free(callptr);
}

void dynamicmatrices(){
	//Creating a matrix using dynamic arrays using calloc

	int** u;	//creating pointer pointing to address of address of int value
	u = (int** )calloc(3, sizeof(int)); //giving u the address of address of int value

	for(unsigned row = 0; row < 3; ++row){
			*(u+row) = (int*)calloc(3, sizeof(int)); //giving *(u+i) the address of int value

			for(unsigned col = 0; col< 3; ++col){
					*(*(u+row)+col) = row*col;		//giving*(*(u+i)+j) the value 
			}

	}
	for(unsigned row = 0; row < 3; ++row){
			
			for(unsigned col = 0; col< 3; ++col){
					cout<<*(*(u+row)+col)<<", ";
			}
			cout<<endl;
	}

	//freeing every dynamic row
	for(unsigned row = 0; row < 3; ++row){
			free(*(u+row));

	}
	//freeing the dynamic matrix

	free(u);
	//REMEMBER FOR EVERY MALLOC, CALLOC OR NEW THERE HAS TO BE A FREE OR A DELETE RESPECTIVELY


}

void null_pointer(){
	//usually if pointer if pointing to address 0, it is refered as a null pointer
	
	
	//Null pointer
	//pointer pointing to nothing is a null pointer
	//it is pointing to a 0 address location
	int* m;
	m = nullptr;
	cout<<m<<endl;	//address 0, *m has no value 

	//m = NULL;		//pointing to null address same as nullptr however above one is better
	void* nb;
	nb = (void* )0;	//type casting (int)0 -> void* which is basically nullpointer


}


int add(int a, int b){return a+b;}
int sub(int a, int b){return a-b;}
int mul(int a, int b){return a*b;}
int Div(int a, int b){return a/b;}

void wrapper(int (**a)(int, int), int b, int c, int option){
			cout<<(*(a + option))(b, c)<<endl;

}


void function_pointers(){
	//These pointers point to functions or a code
	int (*funcptr)(int, int); //if the brackets are removedlike this int* funcptr(int, int )
							  //then it  means the funcptr accepts 2 int and RETURNS a 
							  //pointer to address of integer which we dont want
	//instead it type (*funcptr)(args) is a function pointer pointing 
	//to function or block of code of a return type
	funcptr = &add;	//remove & it still works
	cout<<(*funcptr)(3,4)<<endl;	//remove * it still works

	//we can also have an array of function pointers

	//initializing an array which gives a pointer pointing to
	// the address of the address of the function
	int (*funcptr_arr [])(int, int)  = {add, sub, mul, Div};

	for(size_t idx = 0; idx < sizeof(funcptr_arr)/sizeof(*funcptr_arr); ++idx){

			cout<<(*(funcptr_arr + idx))(5,2)<<endl;
	}

	int (**ptr)(int, int) = funcptr_arr;

	//we can also pass function pointers as arguments
	//wrappers

	wrapper(ptr, 24, 2, 3);

}

int main(){
	
	intro_2_pointers();

	arrays_and_pointers();
	
	memory_management();
	
	dynamicmatrices();
	
	null_pointer();
	
	function_pointers();
	
	//MEMCPY
	//it copies bytes from source to destination

	return 0;

}