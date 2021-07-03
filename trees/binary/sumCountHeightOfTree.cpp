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

void inorderPrint(Node *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int countNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sum(Node *root)
{
    if (root == NULL)
        return 0;
    return sum(root->left) + sum(root->right) + root->data;
}

int height(Node *root)
{
    if (root == NULL)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
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
    inorderPrint(root);
    cout << endl;
    cout << "nodes:" << countNodes(root) << endl;
    cout << "sum:" << sum(root) << endl;
    cout << "height:" << height(root) << endl;
    // 4 2 5 1 6 3 7
    // nodes:7
    // sum:28
    // height:3
}