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
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
// takes array(sorted), start and end index, and returns the root node of the constructed Bst
Node *buildBalanced(int array[], int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    // take mid, and in that index of array create a node
    Node *root = new Node(array[mid]);
    // fill the node's left child with elements from start to mid from array
    root->left = buildBalanced(array, start, mid - 1);
    // fill the node's right child with elements from mid to end from array
    root->right = buildBalanced(array, mid + 1, end);
    return root;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};

    Node *root = buildBalanced(a, 0, 4);
    preOrderTraversal(root);
    cout << "\n";
    // 3 1 2 4 5
}