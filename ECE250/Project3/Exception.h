#ifndef NODE_H
#define NODE_H

/*****************************************
 * UW User ID:  uwuserid
 * Submitted for ECE 250
 * Department of Electrical and Computer Engineering
 * University of Waterloo
 * Calender Term of Submission:  (Winter|Spring|Fall) 20NN
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 * the provided code.
 *****************************************/

#include "ece250.h"


template <typename Type>
class BinarySearchTree;


template <typename Type>
class BinarySearchTreeNode{
    private:
		Type       x_value;	
        
	
		BinarySearchTreeNode<Type> *right;
		BinarySearchTreeNode<Type> *left;
		
		

	public:
           
         
  
		BinarySearchTreeNode<Type>( const Type  & = Type());

		Type retrieve() const;
	

		BinarySearchTreeNode *get_right() const;
		BinarySearchTreeNode *get_left() const;
		

		Type min() const;
	
		Type max() const;

		Type sum() const;
		

		bool member( const Type & ) const;

		bool insert( const Type & );
		void clear();

	friend class BinarySearchTree<Type>;
};


template <typename Type>
BinarySearchTreeNode<Type>::BinarySearchTreeNode( const Type  &x ):
x_value( x ),  
right( 0 ),
left( 0 )
{
	// empty constructor
}





template <typename Type>
Type BinarySearchTreeNode<Type>::retrieve() const {
	return x_value;
}



template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTreeNode<Type>::get_left() const {
	return left;
}

template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTreeNode<Type>::get_right() const {
	return right;
}


template <typename Type>
Type BinarySearchTreeNode<Type>::min() const {
	// you may use std::min
	return Type();
}



template <typename Type>
Type BinarySearchTreeNode<Type>::max() const {
	// you may use std::max
	return Type();
}



template <typename Type>
Type BinarySearchTreeNode<Type>::sum() const {
	if ( this == 0 ) {
		// hint...
		return 0;
	} else {
		return 0;
	}
}



template <typename Type>
bool BinarySearchTreeNode<Type>::member( const Type &x) const {
	if ( this == 0 ) {
		return false;
	}

	return false;
}

template <typename Type>
bool BinarySearchTreeNode<Type>::insert(  const Type &x ) {
	return false;
}

template <typename Type>
void BinarySearchTreeNode<Type>::clear() {
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif