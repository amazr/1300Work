CXX=g++
CXXFLAGS=-Wall -Werror -pedantic -std=c++17
all:a
a:
	${CXX} ${FLAGS} Calc.cpp -o Calc
