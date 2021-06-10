Path=$(PWD)


IncludeDir="$(Path)/include"
IncludeHPP = $(wildcard include/*.hpp)


# LONG=long #use this for long doubles
LONG= 

CC=g++
OPT=-O3
STD=-std=c++17

FLG=-I$(IncludeDir) $(OPT) $(STD) -DLONG=$(LONG)

all: example_sadET.run

example_sadET.run:  makefile $(IncludeHPP) example_sadET.cpp
	$(CC) -o example_sadET.run $(FLG) example_sadET.cpp

clean:
	rm example_sadET.run || true