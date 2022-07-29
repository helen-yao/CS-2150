# Helen Yao lab section 103
CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -O2

OBJECTS = TreeCalc.o TreeNode.o TreeCalcTest.o

tree:	$(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o ./a.out

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h
TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h
TreeNode.o: TreeNode.cpp TreeNode.h
