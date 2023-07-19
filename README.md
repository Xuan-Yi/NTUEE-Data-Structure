# Introduction
* This is programming assignment 1 (PA1) for NTUEE Data Structure, taught by Prof. Ho-Lin Chen in Autumn 2022.
* It involves constructing a binary search tree from an unknown tree's post-order output and performing operations on it. For more information, refer to the doc/report.pdf and codes.

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
