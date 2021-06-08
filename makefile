Path=$(PWD)


IncludeDir="$(Path)/include"
IncludeHPP = $(wildcard include/*.hpp)


LONG=long #this is for later use when I'll introduce the option to use long double

CC=g++
OPT=-O3
STD=-std=c++17

FLG=-I$(IncludeDir) $(OPT) $(STD) -DLONG=$(LONG)

all: example_SAD_ET.run

example_SAD_ET.run:  makefile $(IncludeHPP) example_SAD_ET.cpp
	$(CC) -o example_SAD_ET.run $(FLG) example_SAD_ET.cpp

clean:
	rm example_SAD_ET.run || true