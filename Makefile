CC = g++
DEBUG = -g
STD = -std=c++11


all: run

run: int float str adt
	./int
	./float
	./str
	./adt

int: int.cpp tree.h key.h
	$(CC) $(DEBUG) $(STD) int.cpp -o int

float: float.cpp tree.h key.h
	$(CC) $(DEBUG) $(STD) float.cpp -o float

str: str.cpp tree.h key.h
	$(CC) $(DEBUG) $(STD) str.cpp -o str

adt: adt.cpp tree.h key.h
	$(CC) $(DEBUG) $(STD) adt.cpp -o adt

clean:
	\rm int float str adt

.PHONY: all run

