#ifndef BSTTREE_H
#define BSTTREE_H

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
#include "BinarySearchTreeNode.h"
#include "Exception.h"
#include <iostream>

template <typename Type>
class BinarySearchTree {
    private:
		BinarySearchTreeNode<Type> *tree_root;
		int count;

	public:
		BinarySearchTree();
		~BinarySearchTree();

		// Accessors

		int size() const;
		bool empty() const;

		Type min() const;	
		Type max() const;	
		Type sum() const;
	
	
	    


		BinarySearchTreeNode<Type> *root() const;
		bool member( const Type  &) const;

		// Mutators
       
		void insert( const Type &);
		void clear();

};


template <typename Type>
BinarySearchTree<Type>::BinarySearchTree():
tree_root( 0 ), 
count( 0 ) {
	// empty constructor
}

template <typename Type>
BinarySearchTree<Type>::~BinarySearchTree() {
    
}

template <typename Type>
int BinarySearchTree<Type>::size() const {
	return count;
}

template <typename Type>
bool BinarySearchTree<Type>::empty() const {
    if (count == 0) {
        return true;
    }
    
	return false;
}

template <typename Type>
Type BinarySearchTree<Type>::min() const {
    if (tree_root -> get_left == 0) {
        return tree_root->retrieve();
    } else {
        return tree_root->get_left->min();
    }
}



template <typename Type>
Type BinarySearchTree<Type>::max() const {
    if (tree_root->get_left==0) {
        return tree_root->retrieve();
    } else {
        return tree_root->get_left->max();
    }
}



template <typename Type>
Type BinarySearchTree<Type>::sum() const {
    if (tree_root == 0) {
        return 0;
    } else {
        return (tree_root->retrieve() + tree_root->get_left()->sum() + 
                tree_root->get_right()->sum());
    }
}

template <typename Type>
BinarySearchTreeNode<Type> *BinarySearchTree<Type>::root() const 
{
	return tree_root;
}

template <typename Type>
bool BinarySearchTree<Type>::member( const Type  &x ) const {
    if (tree_root->retrieve() == 0) {
        return false;
    }
    if (tree_root->retrieve() == x) {
        return true;
    }
    
    if (x < tree_root->retrieve()) {
        return tree_root->get_left()->member(x);
    } else {
        return tree_root->get_right()->member(x);
    }
}

template <typename Type>
void BinarySearchTree<Type>::insert( const Type  &x ) {
    if (tree_root == 0) {
        tree_root = new BinarySearchTreeNode (x);
    } else {
        
    }
}

template <typename Type>
void BinarySearchTree<Type>::clear() {
}

// You can modify this function however you want:  it will not be tested

template <typename Type>
std::ostream &operator << ( std::ostream &out, BinarySearchTree<Type> const &qt ) {
	return out;
}

// Is an error showing up in ece250.h or elsewhere?
// Did you forget a closing '}' ?

#endif