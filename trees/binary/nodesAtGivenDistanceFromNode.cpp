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

// case first, where we look for nodes at distance k from given node in its subtree
void printSubtreeNodes(Node *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    // this is what we were looking for, print this now
    {
        cout << root->data << " ";
        return;
    }
    // call for subtrees decreasing the distance value by 1
    printSubtreeNodes(root->left, k - 1);
    printSubtreeNodes(root->right, k - 1);
}
// in this we combine above function to get those results plus the ones through ancestor
// second case, where we go through given node's ancestor and look for nodes at distance of k on adjacent/opposite/alternate subtree, l for R, or, R for L
int printNodes(Node *root, Node *target, int k)
{
    if (root == NULL)
        return -1; //-1 distance, we didn't find our target
    if (root == target)
    {
        printSubtreeNodes(root, k);
        return 0;
    }

    int leftDistance = printNodes(root->left, target, k);
    // if left distance is not -1, means we found our target in left subtree
    if (leftDistance != -1)
    {
        // current node is at ditance k from our target node, print it
        if (leftDistance + 1 == k)
            cout << root->data << " ";
        else
            // call for ancestral path, we call at ancestor's right, covering distance from root's left to root is 1, and since we call for root's right going there from root covers 1 more so, decrease required distance by 2
            printSubtreeNodes(root->right, k - leftDistance - 2);
        return 1 + leftDistance;
    }

    int rightDistance = printNodes(root->right, target, k);
    // if right distance is not -1, means we found our target in right subtree
    if (rightDistance != -1)
    {
        // current node is at ditance k from our target node, print it
        if (rightDistance + 1 == k)
            cout << root->data << " ";
        else
            // call for ancestral path, we call at ancestor's left, covering distance from root's right to root is 1, and since we call for root's left going there from root covers 1 more so, decrease required distance by 2
            printSubtreeNodes(root->left, k - rightDistance - 2);
        return 1 + rightDistance;
    }
    // didn't get our target
    return -1;
}

int main()
{
    //         1
    //     2       3
    // 4

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    // passing the tree, target which is 2, and distance 1
    printNodes(root, root->left, 1);
    // 4, 1
}