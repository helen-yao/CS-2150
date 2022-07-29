# Helen Yao section 103
CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -O2

OBJECTS = BinarySearchTree.o BinaryNode.o BSTPathTest.o

tree:	$(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o ./a.out

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -O2

OBJECTS = BinarySearchTree.o BinaryNode.o BSTPathTest.o

target:	$(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o ./a.out




BinaryNode.o: BinaryNode.cpp BinaryNode.h
BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h
BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h
