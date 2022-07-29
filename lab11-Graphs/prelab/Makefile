CXX = clang++ $(CXXFLAGS)

CXXFLAGS = -Wall
DEBUG = -g


OBJECTS = topological.o middleearth.o

a.out:	$(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS)
	doxygen Doxyfile


