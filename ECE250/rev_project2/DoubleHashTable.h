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
    //delete occupied and array array
	delete[] occupied;
    delete[] array;
}

template<typename T >
int DoubleHashTable<T >::size() const {
    //return count (number of elements in the array)
	return count;
}

template<typename T >
int DoubleHashTable<T >::capacity() const {
    //return array_size (size of the array)
	return array_size;
}

template<typename T >
double DoubleHashTable<T >::load_factor() const {
    //returns the load factor
	return (double)count/array_size;
}

template<typename T >
bool DoubleHashTable<T >::empty() const {
    //returns true if the array does not have any elements inside
    if (count == 0) {
        return true;
    }
    
	return false;
}

template<typename T >
int DoubleHashTable<T >::h1( T const &obj ) const {
   //calculates the probing
   int h = (int)obj&(array_size-1);
   
    while (h < 0) {
        return h + array_size;
    }
    
	return h;
}

template<typename T >
int DoubleHashTable<T >::h2( T const &obj ) const {
    //calculates offset
    int h = (int)(obj/array_size)&(array_size-1);
    
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
    
    //returns true if obj is inside the array
	int probing = h1(obj);
    int offset = h2(obj);
    
    for (int i=0; i<array_size; i++) {
        //search for the obj with appropriate hash searching (similar to inserting)
        if (array[probing] == obj && occupied[probing] == OCCUPIED) {
            return true;
        } else if (occupied[probing] == EMPTY) {
            break;
        }
        
        probing = (probing + offset) & (array_size - 1);
    }
    
	return false;
}

template<typename T >
T DoubleHashTable<T >::bin( int n ) const {
    //returns the element in nth location of the array
	return array[n];
}

template<typename T >
void DoubleHashTable<T >::insert( T const &obj ) {
    //inserts obj if there obj is not in the array
	if (count == array_size) {
         throw overflow();
	} else {
        if (member(obj)) {
            return;
        }
        
        int probing = h1(obj);
        int offset = h2(obj);
        
        //double hashing technique
        for (int i=0; i<array_size; i++) {
            if (occupied[probing] == OCCUPIED) {
                probing += offset;
                probing &= (array_size - 1);
            } else {
                break;
            }
        }
        
        array[probing] = obj;
        occupied[probing] = OCCUPIED;
        count ++;
	}
}

template<typename T >
bool DoubleHashTable<T >::remove( T const &obj ) {
    
    //deletes obj inside the array if it exists
    if (!member(obj)) {
        return false;
    }
    
    int probing = h1(obj);
    int offset = h2(obj);
    
    //also uses appropriate searching technique to find obj
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
    //clears the array reinitialize all the elements in array to 0
    //also reinitialize all the elements in occupied array to EMPTY 
    for (int i=0; i<array_size; i++) {
        array[i] = 0;
        occupied[i] = EMPTY;
    }
    
    count = 0;
}

template<typename T >
void DoubleHashTable<T >::print() const {
    //prints all the elements in the array
    for (int i=0; i<array_size; i++) {
        std::cout << array[i] << std::endl;
    } 
    return;
}

#endif
