#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// find the index of the element in inorder
int search(int inorder[], int start, int end, int current)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == current)
            return i;
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    //traversing index
    static int index = 0;
    //what if
    if (start > end)
        return NULL;
    //preorder's first index is root node
    int current = preorder[index];
    index++;
    //create and store value of that root node in a 'node' variable
    Node *node = new Node(current);
    //base condition
    if (start == end)
    {
        return node;
    }
    // search for that element which we got on preorder in inorder for its index
    int pos = search(inorder, start, end, current);
    // recursively call for left and right subtree building
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    //return the node to build a tree
    return node;
}

// to print the tree inorder
void inorderPrint(Node *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTree(preorder, inorder, 0, 4);
    inorderPrint(root);
}