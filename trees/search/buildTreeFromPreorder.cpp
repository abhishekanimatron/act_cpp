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

void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// returns the root of tree built from preorder
// takes in preorder in array form, a pointer to preorder's index, the value at index, maximum value allowed for that node and minimum one, and also size of the array
Node *constructFromPreorder(int preorder[], int *preorderIndex, int key, int minimum, int maximum, int size)
{
    // if index is greater than size, that means no more node can be built
    if (*preorderIndex >= size)
        return NULL;
    // node which will be created
    Node *root = NULL;
    // if the value of key satisfies conditions for BST
    if (key > minimum && key < maximum)
    {
        // assign our node to that node with key as its value
        root = new Node(key);
        // increment preorder's index value
        *preorderIndex = *preorderIndex + 1;
        // if index is valid, less than size of array
        if (*preorderIndex < size)
        {
            // call for this node's left child
            // with minimum as minimum value passed, and key as maximum value allowed, as this will be our node's left subtree
            root->left = constructFromPreorder(preorder, preorderIndex, preorder[*preorderIndex], minimum, key, size);
        }
        // if index is still valid, less than size of array
        if (*preorderIndex < size)
        {
            // call for this node's right child
            // with maximum as maximum value passed, and key as minimum value allowed, as this will be our node's right subtree
            root->right = constructFromPreorder(preorder, preorderIndex, preorder[*preorderIndex], key, maximum, size);
        }
    }
    return root;
}

int main()
{
    int preorder[] = {10, 2, 1, 13, 11};
    int size = 5;
    int preorderIndex = 0;
    Node *root = constructFromPreorder(preorder, &preorderIndex, preorder[0], INT_MIN, INT_MAX, size);
    preOrderTraversal(root);
    // 10 2 1 13 11
}