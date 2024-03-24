reootDir="./"

IncludeDir="$(reootDir)/include"
IncludeHPP = $(shell find include/ -type f -name '*.hpp')

CC=g++
OPT=-O3
STD=-std=c++20#you need c++20 for the constants

FLG=-I$(IncludeDir) $(OPT) $(STD) -Wall -pedantic -ftemplate-depth=9999999


all: test.run test_simplifications.run examples

test.run: test.cpp makefile $(IncludeHPP)
	$(CC) -o $@ $< $(FLG)

test_simplifications.run: test_simplifications.cpp makefile $(IncludeHPP)
	$(CC) -o $@ $< $(FLG) 


examples:
	cd Examples && $(MAKE) all


clean:
	rm test.run || true
	rm test_simplifications.run || true
	rm sum.run || true

	cd Examples && $(MAKE) clean