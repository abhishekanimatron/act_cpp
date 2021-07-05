#include <iostream>
#include <climits>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// for each node we store this info of it
struct nodeInfo
{
    // size of current node, maximum & minimum value in subtree, answer having size of bst, boolean for checking if this node satisfies bst's conditons
    int size;
    int maximum;
    int minimum;
    int answer;
    bool isBST;
};

nodeInfo largestBstSize(Node *root)
{
    // if node is null, it means size is 0, minimum and maximum to extreme values, answer is also 0, and it is a BST
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    // if this node is a leaf node, having no left and right child, size is 1, and its value is minimum and maximum both and answer is 1, and this is a BST
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    // information of left and right subtree
    nodeInfo leftInfo = largestBstSize(root->left);
    nodeInfo rightInfo = largestBstSize(root->right);

    // information for current node
    nodeInfo current;
    // size will left subtree size+ right subtree size+ this (1)
    current.size = (1 + leftInfo.size + rightInfo.size);
    // if this satisifes bst conditions
    if (leftInfo.isBST && rightInfo.isBST && leftInfo.maximum < root->data && rightInfo.minimum > root->data)
    {
        current.isBST = true;

        current.minimum = min(leftInfo.minimum, min(rightInfo.minimum, root->data));
        current.maximum = max(leftInfo.maximum, max(rightInfo.maximum, root->data));

        // the answer will be this node's size
        current.answer = current.size;
        return current;
    }
    // if this node doesn't form a bst then
    current.isBST = false;
    current.answer = max(leftInfo.answer, rightInfo.answer);
    return current;
}

int main()
{
    /*     24
          /  \
        22    32
       /
      10
    */
    Node *root = new Node(24);
    root->left = new Node(22);
    root->right = new Node(32);
    root->left->left = new Node(10);

    cout << "Largest: " << largestBstSize(root).answer << endl;
}