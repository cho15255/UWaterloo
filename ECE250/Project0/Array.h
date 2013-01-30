#include <iostream>

using namespace std;

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
 
 
 

class Array {
        private:
                int *array;
                int array_size;

        public:
                Array( int = 10 );
                ~Array();

                // accessors
                int get( int ) const;
                int size() const;
				void print() const;

                // mutators
                void set( int, int );
                void resize( int );
};

Array::Array( int n ) {
	//initialize array_size and array
	array_size = n;

	array = new int [n];
	//initialize all the variables inside array to 0
	for (int i=0; i<array_size; i++)
	{
		array[i] = 0;
	}
}

Array::~Array() {
	//destruct an array
	delete [] array;
}


int Array::get( int n ) const {
	//throws exception when a user inputs an integer that is greater than the array_size
	if( n > array_size || n < 0)
	{
		throw ArrayBoundsException();
	}

	return array[n];   
}
//a method to output all the elements in this array
void Array::print() const{
	
	cout << "Printing array" << endl;

	for (int i=0; i<array_size; i++)
	{
		cout << array[i] << endl;
	}

	cout << "Printing finish!" << endl;
}

int Array::size() const {
	//returns array_size
   return array_size;
}

void Array::set( int n, int value ) {
	//check if user's input is greater than the array_size. if it is greater, it throws an exception.
	if (n > array_size || n < 0)
	{
		throw ArrayBoundsException();
	}
	//sets a value to the element with index n
	array[n] = value;
}

void Array::resize( int n ) {
	//throws an exception if the user inputs a negative number
	if ( n < 0 )
	{
		throw ArrayBoundsException();
	}
	//when array_size is equal to the user input the method executes
	if (n != array_size)
	{
		//creates a new array with size n 
		int *newArray = new int [n];

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

