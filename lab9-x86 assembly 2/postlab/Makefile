CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm
ASFLAGS = -f elf64 -g

OBJECTS = testBinarySearch.o timer.o binarySearch.o

a.out: 	$(OBJECTS)
	$(CXX)	$(CXXFLAGS)   $(OBJECTS)

clean:
	-rm -f *.o *~
