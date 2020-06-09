CXX=g++
CXXFLAGS=-g
LDLIBS=

sorter: sorting.o
	$(CXX) $(CXXFLAGS) sorting.o -o sorter $(LDLIBS)
	

sorting.o: sorting.cpp
	$(CXX) $(CXXFLAGS) -c sorting.cpp

clean:
	rm sorting.o sorter