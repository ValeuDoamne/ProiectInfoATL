CXX=g++ 
CXXFLAGS=-Wall

all: main

main: main.o Registru.o
	$(CXX) $(CXXFLAGS) -o main main.o Registru.o

main.o:	main.cpp Registru.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Registru.o: Registru.cpp Registru.h
	$(CXX) $(CXXFLAGS) -c Registru.cpp
	
clean:
	rm -f main main.o Registru.o
