/*
 * BST.cpp
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

#include "BST.h"
#include <string>
#include <iostream>
using namespace std;

/*
REVIEW PURPUSE FOR MID1

look : copy constructor, destructor




*/
/* Constructors and destructor */

	// Default constructor
  
	BST::BST() {
		root = NULL;
		elementCount = 0;
	}
	
	// Parameterized constructor
    
    BST::BST(int element) {
		root = new BSTNode(element);
		elementCount = 1;	
	}               



/*
initiate root as null. and pass the root and the old root to copy

in copy_BST, 
1, if old root is NULL, set the dest NULL and return dest.
2, if not, create a new memory for the newNode, and put the data in, 
3, call left and right recursively and set that to dest->left and dest->right
so that each call returned value will be automatically assigned to the parent's child



*/
  
    BST::BST(const BST& aBST) {
        root=NULL;
        root = copy_BST(root, aBST.root);
        elementCount = aBST.elementCount;
        
    }
     
    BSTNode* BST::copy_BST(BSTNode* newRoot, BSTNode* oldRoot) {
        if(oldRoot==NULL){
            return NULL;
        }
        else{
            newRoot = new BSTNode(oldRoot->element);
            newRoot->left = copy_BST(newRoot->left, oldRoot->left);
            newRoot->right = copy_BST(newRoot->right, oldRoot->right);
            return newRoot;
        }
       
    
    
    }

/*
    template<class ElementType>  
    BSTNode<ElementType>* BST<ElementType>::copy_BST(BSTNode<ElementType>* newRoot, BSTNode<ElementType>* oldRoot) {
        if(oldRoot==NULL){
            return NULL;
        }
        else{
            newRoot = new BSTNode<ElementType>(oldRoot->element);
            newRoot->left  = copy_BST(newRoot->left,oldRoot->left);
            newRoot->right  = copy_BST(newRoot->right,oldRoot->right);

        }
        return newRoot;

    }

    */
    // Copy constructor
    // template<class ElementType>  
	// BST<ElementType>::BST(const BST<ElementType>& aBST)  
	// {   root = NULL;
    //     //call copy_BST
    //     root = copy_BST(aBST.root,root);
    //     //set the elementCount same as the old BST
    //     elementCount = aBST.elementCount;
	// }

    // Description: create a whole new BST by copying an old BST(deep copy)
	//               this is used from the copy constructor.
	//              .copy each nodes by vising them recursively.
    // template<class ElementType>  
    // BSTNode<ElementType>* BST<ElementType>::copy_BST(BSTNode<ElementType>* src, BSTNode<ElementType>* dest){
    //     //if the old BST is NULL, the new one is also NULL
    //     if(src==NULL){
    //         dest = NULL;
    //     }
    //     else{
    //         //allocate memory to the new Node
    //         dest = new BSTNode<ElementType>();
    //         //copy the element of the old root
    //         dest->element = src->element;
            
    //         //call copy_BST for left&right recursively, and assign them to the dest->left and right
    //         dest->left = copy_BST(src->left,dest->left);
    //         dest->right = copy_BST(src->right,dest->right);
            
    //     }
    //     return dest;
        
    // }

/*
Destructor needs to delete memory space for each nodes.

*/

   
	BST::~BST() {
        if(elementCount==0){
            cout<<"no element to delete"<<endl;
        }
        else{
            deleteNode(root);
            elementCount=0;
        }
    }
/*
void BST::deleteNode(BSTNode* current){
    if(current==NULL)
        return ;
    else{
        deleteNode(current->left);
        deleteNode(current->right);
        delete current;
    }

}
*/

	// Destructor 
    // template<class ElementType> 
	// BST<ElementType>::~BST() {
    //     //call deleteNode and set the elementCount = 0
    //     cout<<"hello this is dtor"<<endl;
    // 	deleteNode(root);
    //     elementCount = 0;
    // }
    
// //this is from bottom
// template<class ElementType> 
// void BST<ElementType>::deleteNode(BSTNode<ElementType>* current){
//     if(current ==NULL)
//         return ;
//     else{
//         deleteNode(current->left);
//         deleteNode(current->right);
//         delete current;
//     }
// }
//from the top
void BST::deleteNode(BSTNode* current){
    if(current==NULL)
        return ;
    else{
       BSTNode* pLeft = current->left;
       BSTNode* pRight = current->right;

    
       delete current;
       deleteNode(pLeft);
       deleteNode(pRight);
    }

}
    // Description: delete all the nodes in BST that are dynamically allocated.
	//               this is used from Destructor at the end of the program to make sure no memory leak.(works, checked with Valgrind)
	//               delete nodes by visiting them recursively, in post-order.
	//template<class ElementType> 
//     void BST<ElementType>::deleteNode(BSTNode<ElementType>* current){
//         //if the tree is NULL, dont do anything
//         if(current==NULL){
//             return ;
//         }
//         else{
//             //use post-order recursive traversal to successfully delete nodes from the bottom.
//             deleteNode(current->left);
//             deleteNode(current->right);
//             delete current;
//         }
//     }
	
/* Getters and setters */

    // Description: Returns the number of elements currently stored in the binary search tree.	
	// Time efficiency: O(1)

	unsigned int BST::getElementCount() const {		

		return this->elementCount;
	}
	

/* BST Operations */

    // Description: Inserts an element into the binary search tree.
	//              This is a wrapper method which calls the recursive insertR( ).
	// Precondition: "newElement" does not already exist in the binary search tree.
    // Exception: Throws the exception "ElementAlreadyExistsException" 
	//            if "newElement" already exists in the binary search tree.
	// Time efficiency: O(log2 n)	

	void BST::insert(const int newElement) {
		
	    // Binary search tree is empty, so add the new element as the root
		if (elementCount == 0) {
			root = new BSTNode(newElement);
            //cout<<"successfully inserted the item "<<newElement<<endl;
			elementCount++;
		}
		else{
		  if ( !insertR(newElement, root) ) {
  	         cout<<"Element already exist"<<endl;
               return ;
  	      }
          else{
              //cout<<"successfully inserted the item "<<newElement<<endl;
          }
        }
  	   return;
  	}
/*
For insertion Sort, first of all, 
    if root is NULL, that means, either BST is NULL, or you went all the way.
    so, root is NULL, return false.
    else,
    if anElement is bigger than current, 
        and if the current doesnt have right child(no bigger element,),
        then, make a new Node and set it as current -> rightchild.
        if the current has a right child, 
        go into the right child recursively 
        so, return inserstR(anElement, current->right);


        so , insert is very simple. 
*/
//redo version of insertR

	bool BST::insertR(const int anElement, BSTNode* current) { 
        
        // if(anElement==current->element){
        //     return false;
        // }
        // else{
            if(anElement>current->element){
                if(!(current->hasRight())){
                    BSTNode* newNode = new BSTNode(anElement);
                    current->right = newNode;
                    elementCount++;
                    return true;
                }
                else{
                    return insertR(anElement, current->right);
                }

            }
            if(anElement<=current->element){
                if(!(current->hasLeft())){
                    BSTNode* newNode = new BSTNode(anElement);
                    current->left = newNode;
                    elementCount++;
                    return true;
                }
                else{
                    return insertR(anElement, current->left);
                }
            }
       // }
        return false;



    }

    // Description: Recursive insertion into a binary search tree.
	//              Returns true when "anElement" has been successfully inserted into the 
	//              binary search tree. Otherwise, returns false.
    // template<class ElementType>
	// bool BST<ElementType>::insertR(const ElementType& anElement, BSTNode<ElementType>* current) { 
    //     //if current's element = anElement, return false;
    //     if(current->element==anElement){
    //         return false;
    //     }
    //     //if cuurent's elemt is not anelement,
    //     else{
           
    //         //(if newElement > current'element, 
    //         if(anElement > current->element){
    //              //and if current has right child, call right child recursively
    //             if(current->hasRight()){
    //                 return insertR(anElement, current->right);
    //             }
    //             //if current doesnt have righ child, make a new node with an ELemnt and set the node to current's rightChild, Count++, return true)
    //             else{
    //                 BSTNode<ElementType>* newNode = new BSTNode<ElementType>(anElement);
    //                 current->right = newNode;
    //                 elementCount++;
    //                 return true;
    //             }
    //         }
    //         //else if newElement < current's element,
    //         else if(anElement < current->element){
    //             //and if current has left child, call left child recursively
    //             if(current->hasLeft()){
    //                 return insertR(anElement, current->left);
    //             }    
    //             //if no right child, create a new node with new element, 
    //             //set that to current's leftChild, Count++ return true
    //              else{
    //                 BSTNode<ElementType>* newNode = new BSTNode<ElementType>(anElement);
    //                 current->left = newNode;
    //                 elementCount++;
    //                 return true;
    //             }

    //         }
            
    //     }
    //     return false;
	// } //end of insertR

	
    // Description: Retrieves "targetElement" from the binary search tree.
	//              This is a wrapper method which calls the recursive retrieveR( ).
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Exception: Throws (propagates) the exception "ElementDoesNotExistException" 
	//            thrown from the retrieveR(...)
	//            if "targetElement" is not in the binary search tree.
	// Time efficiency: O(log2 n)

    int BST::retrieve(const int targetElement) const {
        
	    // Check precondition: If binary search tree is empty
		if (elementCount == 0)  {}
			//throw EmptyDataCollectionException("Binary search tree is empty.");
		
		// Otherwise, search for it		
		int translated = retrieveR(targetElement, root);

		return translated;
	}


/*
if current is NULL, return false;->throw exception.
if not, if target > current, call current->right
            target < current, call current ->left;
*/

    int BST::retrieveR(const int targetElement, BSTNode* current) const {
        if(current==NULL){
            //throw ElementDoesNotExistException("targetElement does not exist in this BST.");
        }

        if(current->element==targetElement){
            return current->element;
        }
        else{
            if(targetElement>current->element){
                return retrieveR(targetElement, current->right);
            }
            else{
                return retrieveR(targetElement, current->left);
            }
        }




    }












    // template<class ElementType>
    // ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const {
    //     if (current==NULL){
    //         throw ElementDoesNotExistException("hey it is not here ");
    //     }
    //     else{
    //         if(targetElement>current->element){
    //             return retrieveR(targetElement, current->right);
    //         }
    //         else if(targetElement==current->element)
    //             return current->element;
    //         else{
    //             return retrieveR(targetElement, current->left);
    //         }
    //     }

        
        

    // }
    // Description: Recursive retrieval from a binary search tree.
	// Exception: Throws the exception "ElementDoesNotExistException" 
	//            if "targetElement" is not found in the binary search tree.
    // template<class ElementType>
    // ElementType& BST<ElementType>::retrieveR(const ElementType& targetElement, BSTNode<ElementType>* current) const {
    //     //if current == NULL, throw exception and return nullptr
    //     if(current==NULL){
    //         throw ElementDoesNotExistException("The element does not exist.");
            
    //     }
    //     else{//if target == current's element, return current->element
    //         if(targetElement == current->element){
    //             return current->element;
    //         }
            
            
    //         //else if target > current, call recursively with current-> right
    //         else if(targetElement > current->element)
    //             return retrieveR(targetElement, current->right);
    //          //else if target < current, call recursively with current->left
    //         else{
    //             return retrieveR(targetElement, current->left);
    //         }
    //     }

	// } // end of retrieveR
				
	
    // Description: Traverses the binary search tree in order.
	//              This is a wrapper method which calls the recursive traverseInOrderR( ).
	//              The action to be done on each element during the traverse is the function "visit".
	// Precondition: Binary search tree is not empty.
    // Exception: Throws the exception "EmptyDataCollectionException" 
	//            if the binary search tree is empty.
	// Time efficiency: O(n)		
   
	void BST::traverseInOrder(void visit(const int)) const {
		
		// Check precondition: If binary search tree is empty
		if (elementCount == 0)  {}
			//throw EmptyDataCollectionException("Binary search tree is empty.");

		traverseInOrderR(visit, root);
		
		return;
	}

/*
ok, rootが入ってくるから、inorder ->left current right
    if(current==NULL)
        return ;
    else{
        inOrtderR(visit, current->left);
        visit(root);
        inOrtderR(visit, current->right);
    }
ok.lets do it.


*/    

    // Description: Recursive in order traversal of a binary search tree.	
	
	void BST::traverseInOrderR(void visit(const int), BSTNode* current) const {
        //if current is NULL, return 
        if(current==NULL)
            return ;

        //else, call left
        //      print current   => in-Order method
        //       call right
        else{
            traverseInOrderR(visit, current->left);
            visit(current->element);
            traverseInOrderR(visit, current->right);
        }
       ;
	}// end of traverseInOrderR

    unsigned int BST::nodesCount(){
        static unsigned int count = 0;
        unsigned int* pToCount = &count;
        int result = nodesCountR(root,pToCount);
        return result;
    }

    unsigned int BST::nodesCountR(BSTNode* root , unsigned int* p){
        if(root==NULL){
            return 0;
        }
        else{
            return 1 + nodesCountR(root->left, p) + nodesCountR(root->right, p);
        }
    }

    int  BST::min(){
        if(root==NULL){
            return -1;
        }
        else{
           return minR(root);
        }
    }


    int BST::minR(BSTNode* root){
        if(root->left==NULL){
            return root->element;
        }
        else{
           return  minR(root->left);
        }
    }

    int  BST::evenCount(){
        if(root==NULL){
            return -1;
        }
        else{
            int count = 0;
            int* pToCount = &count;
            return evenCountR(root, pToCount);
        }

    }

    int BST::evenCountR(BSTNode* root, int * pToCount){
        if(root==NULL)return 0;
        else if(root->element %2==0){
            return 1+ evenCountR(root->left, pToCount) + evenCountR(root->right, pToCount) ;
        }
        else{
            return 0+ evenCountR(root->left, pToCount) + evenCountR(root->right, pToCount) ;
        }
        return 0;
    }

    