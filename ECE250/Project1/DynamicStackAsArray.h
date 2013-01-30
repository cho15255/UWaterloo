#ifndef DYNAMIC_STACK_AS_ARRAY_H
#define DYNAMIC_STACK_AS_ARRAY_H

/*****************************************
 * UW User ID:  uwuserid
 * Submitted for ECE 250
 * Semester of Submission:  (Winter|Spring|Fall) 20NN
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/
 
 #include <iostream>
using namespace std;

#include "Exception.h"
#include "Array.h"

template <typename T>
class DynamicStackAsArray {
    private:
		
		Array<T> *stack ; 
		int ihead, count, initial_size, array_size;

	public:
		DynamicStackAsArray( int = 10 );
		~DynamicStackAsArray();

		T top() const;
		int size() const;
		bool empty() const;
		int capacity() const;

		void push( T const & );
		T pop();
		void clear();
		void print();
	
        void stackResize(int ) ;
};

template <typename T>
DynamicStackAsArray<T>::DynamicStackAsArray( int n ):
count( 0 ),
initial_size( n ),
array_size( n ) {            
      
	   stack = new Array<T>(array_size);
	   // What initial value will you give to ihead ?
}

template <typename T>
DynamicStackAsArray<T>::~DynamicStackAsArray() {
	// Enter your implementation
}

template <typename  T>
T DynamicStackAsArray<T>::top() const {
    
   // Enter your implementation
      
}

template <typename T>
int DynamicStackAsArray<T>::size() const {
	// Enter your implementation
}

template <typename T>
bool DynamicStackAsArray<T>::empty() const {
	// Enter your implementation
}

template <typename T>
int DynamicStackAsArray<T>::capacity() const {
	// Enter your implementation
}

template <typename T>
void DynamicStackAsArray<T>::push( T const &obj ) {
     // Enter your implementation
                
}

template <typename T>
T DynamicStackAsArray<T>::pop() {
	 // Enter your implementation
}

template <typename T>
void DynamicStackAsArray<T>::clear() {
     // Enter your implementation
     
     
}






#endif