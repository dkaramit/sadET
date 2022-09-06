reootDir="./"

IncludeDir="$(reootDir)/include"
IncludeHPP = $(shell find include/ -type f -name '*.hpp')

CC=g++
OPT=-O3
STD=-std=c++2a#you need c++2a for the constants

FLG=-I$(IncludeDir) $(OPT) $(STD) -Wall -pedantic


all: test.run examples open

test.run: test.cpp makefile $(IncludeHPP)
	$(CC) -o $@ $< $(FLG) 

examples:
	cd Examples && $(MAKE) all

open:
	cd open_questions && $(MAKE) all


clean:
	rm test.run || true
	cd Examples && $(MAKE) clean