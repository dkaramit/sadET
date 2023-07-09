reootDir="./"

IncludeDir="$(reootDir)/include"
IncludeHPP = $(shell find include/ -type f -name '*.hpp')

CC=g++
OPT=-O3
STD=-std=c++20#you need c++20 for the constants

FLG=-I$(IncludeDir) $(OPT) $(STD) -Wall -pedantic


all: test.run examples sum

test.run: test.cpp makefile $(IncludeHPP)
	$(CC) -o $@ $< $(FLG) 

sum.run: sum.cpp makefile $(IncludeHPP)
	$(CC) -o $@ $< $(FLG) 

examples:
	cd Examples && $(MAKE) all


clean:
	rm test.run || true
	cd Examples && $(MAKE) clean