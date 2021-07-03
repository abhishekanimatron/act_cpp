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

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

// O(n²)
int diameter(Node *root)
{
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int currentDiameter = leftHeight + rightHeight + 1;

    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);

    return max(currentDiameter, max(leftDiameter, rightDiameter));
}

// O(n)
// height as pointer reference
int diameterOptimized(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int leftHeight = 0;
    int rightHeight = 0;
    int leftDiameter = diameterOptimized(root->left, &leftHeight);
    int rightDiameter = diameterOptimized(root->right, &rightHeight);

    int currentDiameter = leftHeight + rightHeight + 1;
    *height = max(leftHeight, rightHeight) + 1;
    return max(currentDiameter, max(leftDiameter, rightDiameter));
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
    cout << "diameter: " << diameterOptimized(root, &height) << endl;
}