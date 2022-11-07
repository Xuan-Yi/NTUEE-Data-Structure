#include <algorithm>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <tuple>
#include <string>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream infile;
    infile.open(argv[1]);
    ofstream outfile;
    outfile.open(argv[2]);

    // TODO: Please code here
    int treeNum;
    vector<BinarySearchTree> manyTrees;

    // Load input file data
    vector<string> lines;
    string line; // temporary data container
    int itr = 1; // iterator to reading data

    if (!infile.is_open())
    {
        cout << "Failed to open " << argv[1] << "\nProgram aborted.\n";
        exit(0);
    }

    lines.clear();
    while (getline(infile, line))
        lines.push_back(line);

    treeNum = stoi(lines[0]); // get number of tree

    // Main code
    for (int i = 0; i < treeNum; i++)
    {
        int n = stoi(lines[itr]); // get number of nodes in i-th tree
        vector<int> postKeys;

        // read data
        stringstream ss(lines[itr + 1]);
        string s;
        while (getline(ss, s, ' '))
            postKeys.push_back(stoi(s));

        itr += 2; // update iterator

        BinarySearchTree newTree(n, postKeys);

        // line1: preorder traversal & line2: tree height
        int treeHeight;
        vector<int> preorder;

        tuple<int, vector<int>> tup = newTree.PreOrderTraversal();
        treeHeight = get<0>(tup);
        preorder = get<1>(tup);

        for (int i = 0; i < preorder.size() - 1; i++)
            outfile << preorder[i] << " ";
        outfile << preorder[preorder.size() - 1];
        outfile << "\n";

        outfile << treeHeight << "\n";

        // rest lines: maximum values on the BST, from top to bottom
        int *Max = newTree.MaxOfEachDepth();
        for (int i = 0; i < treeHeight - 1; i++)
            outfile << Max[i] << "\n";
        outfile << Max[treeHeight - 1];
        if (i < treeHeight - 1)
            outfile << "\n";
    }

    infile.close();
    outfile.close();
}