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

bool isBst(Node *root, int minimum, int maximum)
{
    // no node, is true, base case
    if (root == NULL)
        return true;
    // if node's data is lesser than minimum or greater than maximum return false
    if (minimum >= root->data || maximum <= root->data)
        return false;
    // check for left & right subtree
    bool leftValid = isBst(root->left, minimum, root->data);
    bool rightValid = isBst(root->right, root->data, maximum);

    return leftValid && rightValid;
}

int main()
{
    //     1
    // 4       8
    Node *root = new Node(1);
    root->left = new Node(4);
    root->right = new Node(8);
    if (isBst(root, INT_MIN, INT_MAX))
        cout << "It is valid BST\n";
    else
        cout << "It isn't a valid BST\n";
    //     5
    // 2       8
    Node *root2 = new Node(5);
    root2->left = new Node(2);
    root2->right = new Node(8);
    if (isBst(root2, INT_MIN, INT_MAX))
        cout << "It is valid BST\n";
    else
        cout << "It isn't a valid BST\n";
}