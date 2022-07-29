CXX = clang++

CXXFLage = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = mergeSort.o testMergeSort.o

a.out: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS)

clean:
	-rm -f *.0 *~
