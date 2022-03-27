#include <iostream>

using namespace std;

int main(){
	
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

	cout<<"Address of callptr is "<<callptr<<endl;
	callptr = NULL;

	if(!callptr){
		cout<<"null pointer, address is "<<callptr<<endl;
	}

	//usually if pointer if pointing to address 0, it is refered as a null pointer
	

}