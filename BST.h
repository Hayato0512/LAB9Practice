/*
 * BST.h
 * 
 * Description: Binary Search Tree data collection ADT class.
 *              Link-based implementation.
 *              Duplicated elements are not allowed.
 *
 * Class invariant: It is always a BST.
 * 
 * Author: Hayato Koyama
 * Date of last modification: March 3rd. 2022
 */

#pragma once

#include "BSTNode.h"
//#include "ElementAlreadyExistsException.h"
//#include "ElementDoesNotExistException.h"
//#include "EmptyDataCollectionException.h"



class BST {
	
private:

	
	BSTNode* root; 
    unsigned int elementCount;           

    /* Utility methods */

	// Description: create a whole new BST by copying an old BST(deep copy)
	//               this is used from the copy constructor.
	//              .copy each nodes by vising them recursively.
	BSTNode* copy_BST(BSTNode* src, BSTNode* dest);

	// Description: delete all the nodes in BST that are dynamically allocated.
	//               this is used from Destructor at the end of the program to make sure no memory leak.(works, checked with Valgrind)
	//               delete nodes by visiting them recursively, in post-order.
	void deleteNode(BSTNode* current);

	// Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
    bool insertR(const int element, BSTNode* current); 
    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    int retrieveR(const int targetElement, BSTNode* current) const;

	// Description: Recursive in order traversal of a binary search tree.	
	void traverseInOrderR(void visit(const int), BSTNode* current) const;
         
		 
public:


    /* Constructors and destructor */
	BST();                               // Default constructor
    BST(int element);           // Parameterized constructor 
	BST(const BST& aBST);   // Copy constructor 
    ~BST();                              // Destructor 
	
	/* Getters and setters */
	unsigned int getElementCount() const;


	unsigned int nodesCount();
	 unsigned int nodesCountR(BSTNode* root,unsigned int* p);
	 int min();
	 int minR(BSTNode* root);
	  int evenCount();
	 int evenCountR(BSTNode* root, int * pToCount);
/*
	getRoot() and setRoot(...) <- are not acceptable getter/setter - can you see why?
	setElementCount(...) <- is not an acceptable setter - can you see why?
*/

    /* BST Operations */
	
    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	
	void insert(const int newElement);	
	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)
	int retrieve(const int targetElement) const;
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)	
	void traverseInOrder(void visit(const int)) const;
	
	
}; // end BST

//#include "BST.cpp"  // Including "BST.cpp" (instead of copying the content of BST.cpp) is another way of creating templates.