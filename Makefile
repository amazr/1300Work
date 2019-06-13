CXX=g++
CXXFLAGS=-Wall -Werror -pedantic -std=c++17
all:a b c d
a:
	${CXX} ${FLAGS} Calc.cpp -o Calc
b:
	${CXX} ${FLAGS} CalcBound.cpp -o CalcBound
c:
	${CXX} ${FLAGS} arrayFun.cpp -o arrayFun
d:
	${CXX} ${FLAGS} tictac.cpp -o tictac
