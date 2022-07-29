CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -g

OBJECTS = heap.o huffmanNode.o huffmandec.o

a.out:	$(OBJECTS)
	$(CXX) $(DEBUG)  $(OBJECTS)

clean:
	-rm -r *.o *~
