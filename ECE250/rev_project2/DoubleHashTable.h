#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

/*****************************************
 * UW User ID:  uwuserid
 * Submitted for ECE 250
 * Semester of Submission:  (Winter|Spring|Fall) 20NN
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "Exception.h"
#include "ece250.h"

enum state { EMPTY, OCCUPIED, DELETED };

template<typename T>
class DoubleHashTable {
    private:
		int count;
		int power;
		int array_size;
		T *array;
		state *occupied;

		int h1( T const & ) const; // first hash function
		int h2( T const & ) const; // second hash function

	public:
		DoubleHashTable( int = 5 );
		~DoubleHashTable();
		int size() const;
		int capacity() const;
		double load_factor() const;
		bool empty() const;
		bool member( T const & ) const;
		T bin( int ) const;

		void print() const;

		void insert( T const & );
		bool remove( T const & );
		void clear();
};

template<typename T >
DoubleHashTable<T >::DoubleHashTable( int m ):
count( 0 ), power( m ),
array_size( 1 << power ), //shifting so array_size is 2^power
array( new T [array_size] ),
occupied( new state[array_size] ) { //allocating new state array.

	for ( int i = 0; i < array_size; ++i ) {
		occupied[i] = EMPTY; //setting all the flag to empty in the beginning
	}
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
	delete [] array;
	delete [] occupied;
}

template<typename T >
int DoubleHashTable<T >::size() const {
	return count; //returns count
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
	return array_size; //returns array_size
}

template<typename T >
double DoubleHashTable<T >::load_factor() const {
	return static_cast<double>(count)/static_cast<double>(array_size); //casting values to double because division between two integers might result a double value.
}

template<typename T >
bool DoubleHashTable<T >::empty() const {
    if(count == 0) //if the count is zero, the hash is empty
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
int result = static_cast<int>(obj) & (array_size-1); //h1 i%M
if(result < 0) //if the result is negative add M
{ 
	result = result + array_size;

}
	return result; 
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
	int result2 = (static_cast<int>(obj/array_size) & (array_size - 1)) | 1; //h2 obj/M % M also oring with 1 to make it an odd number always
	if(result2 < 0)
	{
		result2 = result2 + array_size; //if result is negative add M 
	}
	return result2;
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const { //check if the obj is in the HASH
	int h1status = h1(obj); //running h1 with obj
	int h2status = h2(obj); //running h2 with obj
	for(int i = 0; i < array_size; i++) //looping through the whole array
	{
		int position = h1status + (i*h2status); //position is equal to h1status + istatus
		position = position & (array_size-1); //modding the position by M because it might go over M
		if(array[position] == obj &&  occupied[position] == OCCUPIED) //if the value is in the HASH or occupied
		{
			return true; //return true
		}
		else if (occupied[position] == EMPTY) //if the position is empty then, for sure the value does not exist
		{
			return false;
		}
	}
		return false;


}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {	                 
	return array[n]; //just returning the nth position element
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {

	if(count == array_size)
	{
		throw overflow();
	}
	else
	{
		if(member(obj) == false)
		{
			int h1status = h1(obj); //running h1 with obj
			int h2status = h2(obj); //running h2 with obj

			for(int i = 0; i < array_size; i++) //looping through the whole array
				{
					int position = h1status + (i*h2status); //position is equal to h1status + istatus
					position = position & (array_size-1); //moding the position since it might go over M

					if(occupied[position] == OCCUPIED) //if it is occupied then contiune the loop
						continue;

					else if(occupied[position] == EMPTY || occupied[position] == DELETED) //if the position is empty
					{
							array[position] = obj; //set the element to object
							occupied[position] = OCCUPIED; //flag the position to occupied
							count++; //increment the counter since the a new element is being added
							break; //break out of the loop when done
					}
				}
		}

	}
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
	if(member(obj) == false)
	{
		return false;
	}
	else
	{
		int h1status = h1(obj); //running h1 with obj
		int h2status = h2(obj); //running h2 with obj
		for(int i = 0; i < array_size; i++) //looping through the whole array
		{
			int position = h1status + (i*h2status); //position is equal to h1status + istatus
			position = position % array_size; //modding the position by M because it might go over M
			if(array[position] == obj &&  occupied[position] == OCCUPIED) //if the value is in the HASH or occupied
			{		
				array[position] = 0; //setting the element to zero; clearing
				occupied[position] = DELETED; //setting flag to deleted
				count--; //decrementing counter	
			}

		}
		return true; //return true

	}
}

template<typename T >
void DoubleHashTable<T >::clear() {
	 for(int i = 0; i < array_size; i++)
	 {
		 array[i] = 0; //setting everything to zero
		 occupied[i] = EMPTY; //setting all the flag to empty
	 }
	 count = 0;

}

template<typename T >
void DoubleHashTable<T >::print() const {
      for(int i = 0; i < array_size; i++)
	  {
		  std::cout << array[i] << std::endl;
	  }
	return;
}

#endif