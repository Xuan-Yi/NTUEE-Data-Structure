#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

class BinarySearchTree;

class TreeNode
{
private:
    TreeNode *parent = nullptr;
    TreeNode *leftChild = nullptr;
    TreeNode *rightChild = nullptr;
    int key;

public:
    TreeNode(){};

    friend class BinarySearchTree;
};

class BinarySearchTree
{
private:
    TreeNode *root;
    int treeHeight = 0;
    int *maxKey; // maximum values on the BST, from top to bottom

    void BuildTree(TreeNode *current, queue<TreeNode *> &q);
    void subPostOrderTraversal(TreeNode *current);
    int subPreOrderTraversal(TreeNode *current, vector<int> &preorder); // return max height at current node
    void updateMaxOfEachDepth(TreeNode *current, int depth, int *Max);

public:
    BinarySearchTree(int n, vector<int> &postKeys); // n: number of nodes

    void PostOrderTraversal();
    tuple<int, vector<int>> PreOrderTraversal();
    int *MaxOfEachDepth(); // find out maximum values on the BST, from top to bottom
};