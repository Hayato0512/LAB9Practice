/*
 * testDriver.cpp
 * 
 * Description: Drives the testing of the BST, the BSTNode, 
 *              the WordPair and all the exceptions classes. 
 *
 * Author: AL
 * Last Modification Date: Feb. 2022
 */

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "BST.h"
//#include "WordPair.h"
//#include "ElementAlreadyExistsException.h"
//#include "ElementDoesNotExistException.h"
//#include "EmptyDataCollectionException.h"
//#include "Dictionary.h"
//initially like this void display(const WordPair& anElement)
void display(const int anElement) {
  cout << anElement << endl;
} // end of display


// As you discover what main() does, record your discoveries by commenting the code.
// If you do not like this main(), feel free to write your own.
// Remember, this is a test driver. Feel free to modify it as you wish!
int main(int argc, char *argv[]) {
void (*fun_ptr)(const int) = &display;
  BST bs;
  bs.insert(2);
  bs.insert(2);
  bs.insert(2);
  //bs.insert(1);
  bs.insert(2);
  
  bs.traverseInOrder(fun_ptr);
  cout<<"# of nodes are "<<bs.nodesCount()<<endl;
  cout<<"minimum element is "<<bs.min();
  cout<<"# of even number in this tree is"<<bs.evenCount()<<endl;





    
    //WordPair pair("Hayato", "Koyama");
   // Dictionary<WordPair>* testing = new Dictionary<WordPair>();
   // BST<WordPair> a(pair);
  
    //BST<WordPair>* testing = new BST<WordPair>();
    //BST<WordPair>* testing;
    //testing = &a;
    
    
 
  // string aLine = "";
  // string aWord = "";
  // string englishW = "";
  // string translationW = "";
  // string filename = "myDataFile.txt";
  // string delimiter = ":";
  // size_t pos = 0;
  //WordPair translated;
 
  
  // ifstream myfile (filename);
  // if (myfile.is_open()) {
  // 	cout << "Reading from a file:" << endl; 
  //   while ( getline (myfile,aLine) )
  //   {
  //      pos = aLine.find(delimiter);
  //      englishW = aLine.substr(0, pos);
  //      //cout<<englishW<<endl;
  //      aLine.erase(0, pos + delimiter.length());
  //      translationW = aLine;
  //      WordPair aWordPair(englishW, translationW);
  //      //cout<<aWordPair<<endl;
  //      try {
  //           testing->insert(aWordPair);
  //       }
  //       catch ( ElementAlreadyExistsException&anException ) {
  //           cout<<"detected exception because "<< anException.what()<<endl;
  //       }
  //       //cout<<"testing element Count is "<<testing->getElementCount()<<endl;
	//    // insert aWordPair into "testing" using a try/catch block
  //   }
  //   myfile.close();
    //cout<<endl<<endl<<endl<<endl;
    //BST<WordPair>* testing2 = new BST<WordPair>(a); //even if I pass a local valuable a, the copy constructor recieve it as reference
    //testing2->traverseInOrder((*fun_ptr));          //and tht is the same thing as passing a pointer.
    

    // If user entered "Display" at the command line ...
    // if ( ( argc > 1 ) && ( strcmp(argv[1], "Display") == 0) ) {
    //     // ... then display the content of the BST.
    //     cout<<"Ok, this display section is currently under construction"<<endl;
    // }
    // else if (argc == 1) {//no argument
    //    // while user has not entered CTRL+D
    //    while ( getline(cin, aWord) ) {   

    //       WordPair aWordPair(aWord);
    //       //search this word in the testing BST, if a word is found as a substring, then retrieve that element
    //       try{
    //            WordPair result = testing->retrieve(aWordPair.getEnglish());
    //             cout<<endl<< result<<endl;
    //       }
    //       catch(ElementDoesNotExistException&anException){
    //           cout<<"**NOT FOUND**"<<endl;
    //       }
         
         
    //       // and pring the element.
    //       // retrieve aWordPair from "testing" using a try/catch block
		//   // print aWordPair

    //    }
    // }
 // }
  //else 
    //cout << "Unable to open file"; 
  
  return 0;
}