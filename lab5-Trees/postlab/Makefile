#Helen Yao section 103
CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -O2 -g

OBJECTS = AVLTree.o AVLNode.o AVLPathTest.o

target:	$(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o ./a.out

.PHONY: clean
clean:
	-rm -f *.o *~ a.out


AVLNode.o: AVLNode.cpp AVLNode.h
AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h
AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h


