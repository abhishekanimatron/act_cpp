#include <iostream>
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

// inserts the node to its place in a BST
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    // if less call for left subtree & put it to left child
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    // if more call for right subtree & put it to right child
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}

void inOrderPrinter(Node *root)
{
    if (root == NULL)
        return;
    inOrderPrinter(root->left);
    cout << root->data << " ";
    inOrderPrinter(root->right);
}
int main()
{
    Node *root = new Node(1);
    insert(root, 3);
    insert(root, 4);
    insert(root, 9);
    insert(root, 12);
    insert(root, 2);
    insert(root, 7);
    inOrderPrinter(root);
    // 1 2 3 4 7 9 12
}