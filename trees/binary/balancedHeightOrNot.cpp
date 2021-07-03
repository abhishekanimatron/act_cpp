#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Brute approach O(n^2)
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) != true)
        return false;
    if (isBalanced(root->right) != true)
        return false;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (abs(leftHeight - rightHeight) > 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

// Optimized
bool isBalancedOptimized(Node *root, int *height)
{
    if (root == NULL)
        return true;

    int leftHeight = 0;
    int rightHeight = 0;
    if (isBalancedOptimized(root->left, &leftHeight) == false)
        return false;
    if (isBalancedOptimized(root->right, &rightHeight) == false)
        return false;
    *height = max(leftHeight, rightHeight) + 1;
    if (abs(leftHeight - rightHeight) > 1)
        return false;
    else
        return true;
}
int main()
{

    //      tree:
    //           1
    //     2          3
    //   4   5      6   7
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    int height = 0;
    if (isBalancedOptimized(root, &height))
    {
        cout << "Balanced hai" << endl;
    }
    else
    {
        cout << "Balanced nahi hai\n";
    }
}