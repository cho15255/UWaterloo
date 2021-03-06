//#include <iostream>
//
//using namespace std;

#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"

/*****************************************
 * UW User ID:  jh9cho
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/
 
 
 
template <typename T>
class Array {
        private:
                T *array;
                int array_size;

        public:
                Array( int = 10 );
                ~Array();

                // accessors
                T get( int ) const;
                int size() const;

                // mutators
                void set( int, T );
                void resize( int );
};

template <typename T>
Array<T>::Array( int n ) {
	//initialize array_size and array
	array = new T [n];
	array_size = n;

	//initialize all the variables inside array to 0
	for (int i=0; i<array_size; i++)
	{
		array[i] = 0;
	}
}

template <typename T>
Array<T>::~Array() {
	//destruct an array
	delete [] array;
}

template <typename T>
T Array<T>::get( int n ) const {
	//throws exception when a user inputs an integer that is greater than the array_size
	if( n > array_size || n < 0) {
		throw ArrayBoundsException();
	} else {
		return array[n];
	}	
}

template <typename T>
int Array<T>::size() const {
	//returns array_size
   return array_size;
}

template <typename T>
void Array<T>::set( int n, T value ) {
	//check if user's input is greater than the array_size. if it is greater, it throws an exception.
	if (n > array_size || n < 0) {
		throw ArrayBoundsException();
	} else {
		//sets a value to the element with index n
		array[n] = value;
	}
}

template <typename T>
void Array<T>::resize( int n ) {

	//when array_size is equal to the user input the method executes
	if (n != array_size)
	{
		//creates a new array with size n 
		T *newArray = new T [n];

		if (n > array_size)
		{
			//copies all the elements in old array to new array when user input is greater than array_size
			for (int i=0; i<array_size; i++)
			{
				newArray[i] = array[i];
			}
			//initialize elements after index array_size to 0
			for (int i=array_size; i<n; i++)
			{
				newArray[i] = 0;
			}
		}
		else
		{
			//copies all the elements in old array to new array up to index n
			for (int i=0; i<n; i++)
			{
				newArray[i] = array[i];
			}
		}
		
		//destruct the old array
		delete [] array;
		//points old array variable's memory location to the new array memory location
		array = newArray;
		//change the array_size value
		array_size = n;
	}
}

#endif

