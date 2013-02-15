#ifndef DOUBLE_HASH_TABLE_H
#define DOUBLE_HASH_TABLE_H

/*****************************************
 * UW User ID:  jh9cho
 * Submitted for ECE 250
 * Semester of Submission:  (Winter) 2013
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
array_size( 1 << power ),
array( new T [array_size] ),
occupied( new state[array_size] ) {
    
	for ( int i = 0; i < array_size; ++i ) {
		occupied[i] = EMPTY;
	}
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
    
	delete[] occupied;
    delete[] array;
}

template<typename T >
int DoubleHashTable<T >::size() const {
    
	return count;
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
    
	return array_size;
}

template<typename T >
double DoubleHashTable<T >::load_factor() const {
    
	return (double)count/array_size;
}

template<typename T >
bool DoubleHashTable<T >::empty() const {
    
    if (count == 0) {
        return true;
    }
    
	return false;
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
   
   int h = static_cast<int>(obj)&(array_size-1);
   
    while (h < 0) {
        return h + array_size;
    }
    
	return h;
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
    
    int h = static_cast<int>(obj)(obj/array_size)&(array_size-1);
    
    while (h < 0) {
        h = h + array_size;   
    }
    
    if (h%2 == 0) {
        h += 1;
    }
    
	return h;
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const {
	int probing = h1(obj);
    int offset = h2(obj);
    
    for (int i=0; i<array_size; i++) {
        if (array[probing] == obj) {
            return true;
        }
        
        else if (occupied[probing] == EMPTY) {
            break;
        }
        
        probing = (probing + offset) & (array_size - 1);
    }
    
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
	return array[n];
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
    
    if (!member(obj)) {
        return false;
    }
    
    int probing = h1(obj);
    int offset = h2(obj);
    
    while (array[probing] != obj) {
        probing = (probing + offset) & (array_size - 1);
    }
    
    array[probing] = 0;
    occupied[probing] = DELETED;
    count --;
    
    return true;
}

template<typename T >
void DoubleHashTable<T >::clear() {
    for (int i=0; i<array_size; i++) {
        array[i] = 0;
        occupied[i] = EMPTY;
    }
    
    count = 0;
}

template<typename T >
void DoubleHashTable<T >::print() const {
    // enter your implemetation here 	
    return;
}

#endif