/*
 * BSTNode.h
 * 
 * Description: Models a node required to build a link-based binary search tree (BST).
 * 
 * Author: AL
 * Date of last modification: Feb. 2022
 */

#pragma once
#include <iostream>
using namespace std;


class BSTNode {

public:

	int element;
	BSTNode* left;
	BSTNode* right;

	// Constructors
	BSTNode() ;
    BSTNode(int element) ;
    BSTNode(int element, BSTNode* theLeftSubTree, BSTNode* theRightSubTree) ;

	// Boolean helper functions
	bool isLeaf() const;
	bool hasLeft() const;
	bool hasRight() const;

};

//#include "BSTNode.cpp" // Including "BSTNode.cpp" (instead of copying the content of BSTNode.cpp) 
                       // is another way of creating templates.