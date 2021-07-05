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

// inserts into bst
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (root->data < value)
    {
        root->right = insert(root->right, value);
    }
    else
        root->left = insert(root->left, value);
    return root;
}

// searches for target in the tree and returns that node
Node *search(Node *root, int target)
{
    if (root == NULL)
        return NULL;

    // if data matches target, return that
    if (root->data == target)
        return root;
    // if target is smaller call for left subtree
    if (root->data > target)
        return search(root->left, target);
    // else call for right subtree
    return search(root->right, target);
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

    if (search(root, 99) != NULL)
        cout << "It exists.\n";
    else
        cout << "It doesn't exist.\n";
}