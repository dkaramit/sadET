Path=$(PWD)


IncludeDir="$(Path)/include"
IncludeHPP = $(shell find include/ -type f -name '*.hpp')


# LONG=long #use this for long doubles
LONG= 

CC=g++
OPT=-O2
STD=-std=c++17

FLG=-I$(IncludeDir) $(OPT) $(STD) -DLONG=$(LONG)


all: example_sadET.run test_sadET.run

example_sadET.run:  makefile $(IncludeHPP) example_sadET.cpp
	$(CC) -o example_sadET.run $(FLG) example_sadET.cpp

test_sadET.run:  makefile $(IncludeHPP) test_sadET.cpp
	$(CC) -o test_sadET.run $(FLG) test_sadET.cpp


clean:
	rm example_sadET.run || true
	rm test_sadET.run || true