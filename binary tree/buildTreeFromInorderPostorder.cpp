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

Node *buildTree(int postorder[], int inorder[], int start, int end)
{
    //traversing index number
    static int index = 4;
    //what if
    if (start > end)
        return NULL;
    //postorder's last index is root node
    int current = postorder[index];
    index--;
    //create and store value of that root node in a 'node' variable
    Node *node = new Node(current);
    //base condition
    if (start == end)
        return node;
    // search for that element which we got on preorder in inorder for its index
    int pos = search(inorder, start, end, current);
    // recursively call for right and left subtree building
    node->right = buildTree(postorder, inorder, pos + 1, end);
    node->left = buildTree(postorder, inorder, start, pos - 1);

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
    int postorder[] = {4, 2, 5, 3, 1};
    int inorder[] = {4, 2, 1, 5, 3};

    Node *root = buildTree(postorder, inorder, 0, 4);
    inorderPrint(root);
}