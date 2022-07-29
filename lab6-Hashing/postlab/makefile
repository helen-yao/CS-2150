#Helen Yao section 103
CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -O2 -g

OBJECTS = wordPuzzle.o hashTable.o timer_test.o timer.o 

target: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o ./a.out

.PHONY: clean
clean:
	-rm -f *.o *~a.out



hashTable.o: hashTable.cpp hashTable.h
timer.o: timer.cpp timer.h
timer_test.o: timer_test.cpp timer.h
wordPuzzle.o: wordPuzzle.cpp hashTable.cpp hashTable.h

