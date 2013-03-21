/*************************************************
 * BinarySearchTree_tester<Type>
 * A class for testing a BinarySearchTree.
 *
 * Author:  Douglas Wilhelm Harder
 * Copyright (c) 2006-9 by Douglas Wilhelm Harder.  All rights reserved.
 *
 * DO NOT EDIT THIS FILE
 *************************************************/

#ifndef BINARYSEARCHTREE_TESTER_H    // include guards
#define BINARYSEARCHTREE_TESTER_H

#include "Exception.h"
#include "Tester.h"
#include "BinarySearchTree.h"
#include "BinarySearchTreeNode.h"
#include "BinarySearchTreeNode_tester.h"


#include <iostream>

template <typename Type>
class BinarySearchTree_tester:public Tester< BinarySearchTree<Type> > {
	using Tester< BinarySearchTree<Type> >::object;
	using Tester< BinarySearchTree<Type> >::command;

	public:
		BinarySearchTree_tester( BinarySearchTree<Type> *obj = 0 ):Tester< BinarySearchTree<Type> >( obj ) {
			// empty
		}

		void process();
};

/****************************************************
 * void process()
 *
 * Process the current command.  For BinarySearhTree. 
 * Commands are:
 *
 *  Accessors
 *
 *   size n          size            the size equals n
 *   empty b         empty           the result is the boolean value b
 *
 *   min x         min_x           x is the smallest value in the tree
 *   max x         max_x           x is the largest value in the tree
 *
 *   sum x         sum_x           x is the sum of the x values in the tree
 *   root            root            the root is not 0 and starts a BinarySearhTree_node_tester on that
 *                                   node until the 'exit' command is typed
 *   root0           root            the root is 0
 *   member x  b    member          x is a member of the tree
 *
 *  Mutators
 *
 *   insert x       insert          insert the value x into the tree ignoring duplicates
 *   clear           clear           deletes all the children from the tree
 *
 *  Others
 *   cout            cout << list    print the list (for testing only)
 *   summary                         prints the amount of memory allocated
 *                                   minus the memory deallocated
 *   details                         prints a detailed description of which
 *                                   memory was allocated with details
 *
 ****************************************************/
template <typename Type>
void BinarySearchTree_tester<Type>::process() {
	if ( command == "size" ) {
		// check if the size equals the next integer read

		int expected_size;

		std::cin >> expected_size;

		int actual_size = object->size();

		if ( actual_size == expected_size ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in size(): expecting the value '" << expected_size << "' but got '" << actual_size << "'" << std::endl;
		}
	} else if ( command == "empty" ) {
		// check if the empty status equals the next boolean read

		bool expected_empty;

		std::cin >> expected_empty;

		bool actual_empty = object->empty();

		if ( actual_empty == expected_empty ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in empty(): expecting the value '" << expected_empty << "' but got '" << actual_empty << "'" << std::endl;
		}
	} else if ( command == "min" ) {
		// checks if the smallest x value is that returned by this function

		Type expected_min;

		std::cin >> expected_min;

		Type actual_min = object->min();

		if ( actual_min == expected_min ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in min(): expecting the value '" << expected_min << "' but got '" << actual_min << "'" << std::endl;
		}
	
	} else if ( command == "max" ) {
		// checks if the largest x value is that returned by this function

		Type expected_max;

		std::cin >> expected_max;

		Type actual_max = object->max();

		if ( actual_max == expected_max ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in max(): expecting the value '" << expected_max<< "' but got '" << actual_max << "'" << std::endl;
		}
	
	} else if ( command == "sum" ) {
		// checks if the sum of the x values is that returned by this function

		Type expected_sum;

		std::cin >> expected_sum;

		Type actual_sum = object->sum();

		if ( actual_sum == expected_sum ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in sum(): expecting the value '" << expected_sum << "' but got '" << actual_sum << "'" << std::endl;
		}
	
	} else if ( command == "root" ) {
		// checks that the root is not 0, and if it is not,
		// the next object gives the number of commands which should
		// be tested by the BinarySearchTreeNode_tester

		BinarySearchTreeNode<Type> *actual_root = object->root();

		if ( actual_root == 0 ) {
			std::cout << "Failure in root(): expecting a non-zero root pointer" << std::endl;
		} else {
			std::cout << "Okay" << std::endl;

			BinarySearchTreeNode_tester<Type> tester( actual_root );

			tester.run();
		}
		
		
	} else if ( command == "root0" ) {
		// check that the root pointer is 0

		if ( object->root() == 0 ) {
			std::cout << "Okay" << std::endl;
		} else {
			std::cout << "Failure in root(): expecting a 0 root pointer" << std::endl;
		}
	} else if ( command == "member" ) {
		// check if the next object read in is in the linked list

		Type element_x;		
		bool membership;

		std::cin >> element_x;
		
		std::cin >> membership;

		if ( object->member( element_x ) == membership ) {
			std::cout << "Okay" << std::endl;
		} else {
			if ( membership ) {
				std::cout << "Failure in member(): expecting the value (" << element_x << ") to be in the BinarySearchTree" << std::endl;
			} else {
				std::cout << "Failure in member(): not expecting the value (" << element_x << ") to be in the BinarySearchTree" << std::endl;
			}
		}
	} else if ( command == "insert" ) {
		// insert the next pair into the BinarySearchTree

		Type x;

		std::cin >> x;
		

		object->insert( x );
		std::cout << "Okay" << std::endl;
	} else if ( command == "clear" ) {
		// delete all the nodes in the tree

		object->clear();
		std::cout << "Okay" << std::endl;
	} else if ( command == "cout" ) {
		std::cout << *object << std::endl;
	} else {
		std::cout << command << ": Command not found." << std::endl;
	}
}

#endif