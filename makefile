Path=$(PWD)


IncludeDir="$(Path)/include"
IncludeHPP = $(wildcard include/*.hpp)


LONG=long #this is for later use when I'll introduce the option to use long double

CC=g++
OPT=-O3
STD=-std=c++17

FLG=-I$(IncludeDir) $(OPT) $(STD) -DLONG=$(LONG)

all: example_ExTADL.run

example_ExTADL.run:  makefile $(IncludeHPP) example_ExTADL.cpp
	$(CC) -o example_ExTADL.run $(FLG) example_ExTADL.cpp

clean:
	rm example_ExTADL.run || true