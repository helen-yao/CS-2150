CXX = clang++

CXXFLAGS = -Wall -g

AS = nasm

ASFLAGS = -f elf64 -g

OBJECTS = mathlib.o mathfun.o

a.out: $(OBJECTS)
	$(CXX) $(CXXGLAGS) $(OBJECTS)

clean:
	-rm -f *.o *~
