# Introduction
* This is programming assignment 1 (PA1) of NTUEE Data Structure, lectured by Professor Chan at 2022, Autumn.
* This is about building a binary search tree from a post order output of that unknown tree, then apply apply some operations on it. Detailes are in doc/report.pdf and codes.  

# Makefile Commands

## Compile
* The following commands will compile two executables:
  1. **bst**: main program
  2. **lib/compare**: program to compare content of two files
```bash
# compile bst and lib/compare
make
```

## Run **bst**
* Commands are in the format
```bash
./bst <input_file_name> <output_file_name>
```
* An example is
```bash
./bst inputs/public1.dat outputs/public1_ans.dat
```

## Compare output file to the corresponding answer file
* Commands are in the format
```bash
./lib/compare <output_file_name> <input_file_path>
```
* An example is
```bash
./lib/compare outputs/public1_ans.dat answers/public1_ans.dat
```
