CXX = clang $(CXXFLAGS)

CXXFLAGS = -Wall -O2 -g

OBJECTS = linkedlist.o

target: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o ./a.out

clean:
	-rm -f *.o *~a.out
