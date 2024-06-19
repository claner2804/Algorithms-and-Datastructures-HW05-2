CXX = g++
CXXFLAGS = -Wall -std=c++11

all: sort

sort: main.o mergesort.o
	$(CXX) $(CXXFLAGS) -o sort main.o mergesort.o

main.o: main.cpp mergesort.h
	$(CXX) $(CXXFLAGS) -c main.cpp

mergesort.o: mergesort.cpp mergesort.h
	$(CXX) $(CXXFLAGS) -c mergesort.cpp

clean:
	rm -f *.o sort
