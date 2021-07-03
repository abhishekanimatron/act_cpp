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
// in-place makes the binary tree a flattened tree, where each node's left child is null, and right is the next node in preorder sequence of tree
void flatten(Node *root)
{
    // base case, meaning tree is already flattened
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;
    // if there is a left child/subtree
    if (root->left != NULL)
    {
        // store right subtree of root in temp Node
        Node *temp = root->right;
        // make the root's left subtree its right subtree
        root->right = root->left;
        // make root's left subtree NULL
        root->left = NULL;
        // to find tail of right subtree
        Node *tail = root->right;
        while (tail->right != NULL)
        { //traverse till there is no right child of tail, that is our last/tail node in right subtree
            tail = tail->right;
        }
        // to tail's right attach our temp node which has stored in itself our original right subtree
        tail->right = temp;
    }
    flatten(root->right);
}

// to print in order
void inOrderPrint(Node *root)
{
    if (root == NULL)
        return;
    inOrderPrint(root->left);
    cout << root->data << " ";
    inOrderPrint(root->right);
}

int main()
{ //      tree:
    //           1
    //     2          3
    //   4   5      6   7
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    inOrderPrint(root);
    // 4 2 5 1 6 3 7
    flatten(root);
    cout << "\n";
    inOrderPrint(root);
    // 1 2 4 5 3 6 7
}