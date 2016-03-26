#This is a comment
CC=g++
CFLAGS=-Wall -std=c++0x
BIN=bin
SRC= $(basename $(wildcard p*.cpp))

all: $(SRC)

p%: p%.cpp
	if [ -d ./bin ]; then echo; else mkdir bin; fi
	$(CC) $(CFLAGS) p$*.cpp -o $(BIN)/p$*

clean:
	rm -r bin

#p%.cpp: p%.cpp
#	echo "Second pattern captured"
#	if [ -d ./bin ]; then echo; else mkdir bin; fi
#	$(CC) $(CFLAGS) p$*.cpp -o $(BIN)/p$*
