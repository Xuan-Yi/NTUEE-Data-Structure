#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree(int n, vector<int> &postKeys)
{
    queue<TreeNode *> postTree;
    // create root TreeNode
    root = new TreeNode;
    root->key = postKeys[n - 1];

    // enqueue all nodes from back except for root
    for (int t = n - 2; t >= 0; t--)
    {
        TreeNode *newNode = new TreeNode;

        newNode->key = postKeys[t];
        postTree.push(newNode);
    }

    // build tree
    while (!postTree.empty())
        BuildTree(root, postTree);

    if (!postTree.empty()) // check if build successfully
    {
        cout << "(BuildTree) error: \n";
        while (!postTree.empty())
        {
            cout << postTree.front()->key << ", ";
            postTree.pop();
        }
        cout << "\n";
    }
}

void BinarySearchTree::BuildTree(TreeNode *current, queue<TreeNode *> &q)
{
    TreeNode *newNode;

    newNode = q.front();
    if (newNode->key > current->key) // is right child
    {
        if (current->rightChild == nullptr) // directly append as right child
        {
            current->rightChild = newNode;
            newNode->parent = current;
            q.pop();
        }
        else
            BuildTree(current->rightChild, q);
    }
    else // is left child
    {
        if (current->leftChild == nullptr) // directly append as left child
        {
            current->leftChild = newNode;
            newNode->parent = current;
            q.pop();
        }
        else
            BuildTree(current->leftChild, q);
    }
}

void BinarySearchTree::PostOrderTraversal()
{
    cout << "=== Post Order Traversal ===\n";
    subPostOrderTraversal(root);
    cout << "\n=== End ===\n";
}

tuple<int, vector<int>> BinarySearchTree::PreOrderTraversal()
{
    tuple<int, vector<int>> tup;

    vector<int> preorder;
    treeHeight = subPreOrderTraversal(root, preorder);

    get<0>(tup) = treeHeight;
    get<1>(tup) = preorder;

    return tup;
}

void BinarySearchTree::subPostOrderTraversal(TreeNode *current)
{
    if (current != nullptr)
    {
        subPostOrderTraversal(current->leftChild);
        subPostOrderTraversal(current->rightChild);
        cout << current->key << " ";
    }
}

int BinarySearchTree::subPreOrderTraversal(TreeNode *current, vector<int> &preorder)
{
    if (current != nullptr)
    {
        preorder.push_back(current->key);
        int m1 = subPreOrderTraversal(current->leftChild, preorder);
        int m2 = subPreOrderTraversal(current->rightChild, preorder);

        return max(m1, m2) + 1;
    }
    else
        return 0;
}

int *BinarySearchTree::MaxOfEachDepth()
{
    maxKey = new int[treeHeight];
    for (int i = 0; i < treeHeight; i++)
        maxKey[i] = -2147483648; // min of int

    updateMaxOfEachDepth(root, 0, maxKey);

    return maxKey;
}

void BinarySearchTree::updateMaxOfEachDepth(TreeNode *current, int depth, int *Max)
{
    Max[depth] = max(Max[depth], current->key);

    if (current->leftChild != nullptr)
        updateMaxOfEachDepth(current->leftChild, depth + 1, Max);
    if (current->rightChild != nullptr)
        updateMaxOfEachDepth(current->rightChild, depth + 1, Max);
}