Path=$(PWD)


IncludeDir="$(Path)/include"
IncludeHPP = $(shell find include/ -type f -name '*.hpp')


CC=g++
OPT=-O3
# STD=-std=c++17
STD=-std=c++2a


FLG=-I$(IncludeDir) $(OPT) $(STD) -Wall

all:test.run

test.run:  makefile $(IncludeHPP) test.cpp
	$(CC) -o test.run $(FLG) test.cpp

clean:
	rm example_sadET.run || true
	rm test.run || true