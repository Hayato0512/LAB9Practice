/*
 * BSTNode.cpp
 * 
 * Description: Models a node required to build a link-based binary search tree (BST).
 * 
 * Author: AL
 * Date of last modification: Feb. 2022
 */
#include <iostream>
#include "BSTNode.h"
using namespace std;

// Constructors

BSTNode::BSTNode() {
	left = NULL;
	right = NULL;
}


BSTNode::BSTNode(int element) {
	this->element = element;
	left = NULL;
	right = NULL;
}


BSTNode::BSTNode(int element, BSTNode* left, BSTNode* right) {
	this->element = element;
	this->left = left;
	this->right = right;	
}

// Boolean helper functions

bool BSTNode::isLeaf() const {
	return (left == NULL && right == NULL);
}


bool BSTNode::hasLeft() const {
	return (left != NULL);
}


bool BSTNode::hasRight() const {
	return (right != NULL);
}