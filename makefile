all: translate

translate: testDriver.o BST.o BSTNode.o 
	g++ -Wall -o translate -g testDriver.o BST.o BSTNode.o 

testDriver.o: testDriver.cpp
	g++ -Wall -c -g testDriver.cpp
		
BST.o: BST.h BST.cpp
	g++ -Wall -c -g BST.cpp

BSTNode.o: BSTNode.h BSTNode.cpp
	g++ -Wall -c -g BSTNode.cpp



clean:
	rm -f translate *.o