#ifndef DYNAMIC_STACK_AS_ARRAY_H
#define DYNAMIC_STACK_AS_ARRAY_H

/*****************************************
 * UW User ID:  jh9cho 
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
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
	   ihead = -1;
}

template <typename T>
DynamicStackAsArray<T>::~DynamicStackAsArray() {
	delete stack;
}

template <typename  T>
T DynamicStackAsArray<T>::top() const {
    
    if (count > 0) {
       return stack->get(ihead);
    } else {
       throw underflow();
    }
}

template <typename T>
int DynamicStackAsArray<T>::size() const {
	return count;
}

template <typename T>
bool DynamicStackAsArray<T>::empty() const {
	if (count == 0) {
        return true;
    } else {
        return false;
    }
}

template <typename T>
int DynamicStackAsArray<T>::capacity() const {
	return array_size;
}

template <typename T>
void DynamicStackAsArray<T>::push( T const &obj ) {
    if (count >= array_size) {
        array_size *= 2;
        stack->resize(array_size);
    }
    count ++;
    ihead ++;

	stack->set(ihead,obj);
}

template <typename T>
T DynamicStackAsArray<T>::pop() {
    if (count <= 0) {
        throw underflow();
    }
    
	T temp = top();

    if (array_size > initial_size && count <= array_size/4) {
        array_size /= 2;
        stack->resize(array_size);
	}

	stack->set(ihead,0);
	ihead--;
	count--;
     
    return temp;
}

template <typename T>
void DynamicStackAsArray<T>::clear() {
    Array<T> *newStack = new Array<T> (initial_size);
    delete [] stack;
    stack = newStack;
}

#endif