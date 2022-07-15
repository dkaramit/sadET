Path=$(PWD)


IncludeDir="$(Path)/include"
IncludeHPP = $(shell find include/ -type f -name '*.hpp')


# LONG=long #use this for long doubles
LONG= 

CC=g++
OPT=-O3
STD=-std=c++17

FLG=-I$(IncludeDir) $(OPT) $(STD) -DLONG=$(LONG) -Wall

all:test_sadET.run

test_sadET.run:  makefile $(IncludeHPP) test_sadET.cpp
	$(CC) -o test_sadET.run $(FLG) test_sadET.cpp

clean:
	rm example_sadET.run || true
	rm test_sadET.run || true