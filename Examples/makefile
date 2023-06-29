reootDir="../"

IncludeDir="$(reootDir)/include"
IncludeHPP = $(shell find include/ -type f -name '*.hpp')

CC=g++
OPT=-O3
STD=-std=c++20#you need c++20 for the constants

FLG=-I$(IncludeDir) $(OPT) $(STD) -Wall -pedantic

EXE = $(shell find . -type f -name '*.cpp' | sed 's/\.cpp/.run/g' | sed 's/\.\///g')

all: $(EXE)


%.run: %.cpp makefile $(IncludeHPP)
	$(CC) -o $@ $< $(FLG) 


clean:
	rm *.run || true