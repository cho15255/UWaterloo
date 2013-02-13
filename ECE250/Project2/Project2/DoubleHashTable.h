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
array_size( 1 << power ),
array( new T [array_size] ),
occupied( new state[array_size] ) {
    
	for ( int i = 0; i < array_size; ++i ) {
		occupied[i] = EMPTY;
	}
}

template<typename T >
DoubleHashTable<T >::~DoubleHashTable() {
    
	delete [] occupied;
    delete [] array;
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
    
	return load_factor;
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
    
    if ((obj)&(array_size-1) < 0) {
        return (obj)&(array_size-1) + array_size;
    }
    
	return (obj)&(array_size-1);
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
    
	if ((obj/array_size)&(array_size-1) < 0) {
        return (obj/array_size)&(array_size-1) + array_size;   
	}
    
	return (obj/array_size)&(array_size-1);
}

template<typename T >
bool DoubleHashTable<T >::member( T const &obj ) const {
	for (int i=0; i<array_size; i++) {
        if (array[i] == obj) {
            return true;
        }
    }
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
	return array[n];
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {
	if (count == array_size) {
         throw overflow();
	}
    
    int probing = h1(obj);
    int offset = h2(obj);
    
    while (occupied[probing] == OCCUPIED) {
        probing = (probing+offset) & (array_size-1);
    }
    
    array[probing] = obj;
    occupied[probing] = OCCUPIED;
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
    // enter your implemetation here 	

    return false;
}

template<typename T >
void DoubleHashTable<T >::clear() {
    for (int i=0; i<array_size; i++) {
        array[i] = 0;
        occupied[i] = EMPTY;
    }
}

template<typename T >
void DoubleHashTable<T >::print() const {
    // enter your implemetation here 	
    return;
}

#endif