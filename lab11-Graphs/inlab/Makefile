CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall -O2
DEBUG = -g


OBJECTS = traveling.o middleearth.o

a.out:	$(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen Doxyfile

