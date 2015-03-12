

all: main.o

main.o: main.cc
	g++ -c -std=c++14 -o main.o main.cc