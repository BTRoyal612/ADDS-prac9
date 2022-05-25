clean :
	rm *.o *.out

all : ExpressionConvert.o main.cpp
	g++ ExpressionConvert.o main.cpp

ExpressionConvert.o : ExpressionConvert.cpp ExpressionConvert.h
	g++ -c ExpressionConvert.cpp -o ExpressionConvert.o
