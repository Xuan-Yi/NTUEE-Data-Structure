.PHONY=all clean run
CC=g++
CFLAGS=-std=c++14 -O2
LDFLAGS=-lstdc++
TARGET=bst compare



all: $(TARGET)

bst: bst.cpp BinarySearchTree.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) -Iinc

compare: lib/compare

lib/compare: lib/compare.cpp
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS) -Iinc

clean:
	rm -f $(TARGET)
	rm -f lib/compare

rmout:
	rm -rf outputs/*.dat