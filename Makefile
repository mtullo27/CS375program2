CFLAGS=-DDEBUG -g -std=c++17
all: program2.o
	g++ -g program2.o -o BestFirstSearch
program2.o: program2.cpp
	g++ -c $(CFLAGS) program2.cpp -o program2.o
clean:
	rm -rf *.o BestFirstSearch
