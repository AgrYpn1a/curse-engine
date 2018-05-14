all: main.cpp src/*.cpp header/*.h
	g++ -Wall -std=c++11 -Iheader -o main main.cpp src/*.cpp -lncurses
run: all
	./main

