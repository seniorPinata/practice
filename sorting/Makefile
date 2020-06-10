CXX=g++
CXXFLAGS=-g
LDLIBS=

sort_app: main.o sorter.o bubble_sorter.o
	$(CXX) $(CXXFLAGS) main.o sorter.o bubble_sorter.o -o sort_app $(LDLIBS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

sorter.o: sorter.cpp
	$(CXX) $(CXXFLAGS) -c sorter.cpp

bubble_sorter.o: bubble_sorter.cpp
	$(CXX) $(CXXFLAGS) -c bubble_sorter.cpp

clean:
	rm sort_app main.o sorter.o bubble_sorter.o