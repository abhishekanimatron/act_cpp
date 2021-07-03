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
// root, and two nodes n1 and n2 of which we have to find shortest distance
//returns the  Least common node/ancestor of the two nodes n1, n2
Node *leastCommonAncestor(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    // if data is same, it is common ancestor
    if (root->data == n1 || root->data == n2)
        return root;
    Node *left = leastCommonAncestor(root->left, n1, n2);
    Node *right = leastCommonAncestor(root->right, n1, n2);
    // this means in left subtree there is n1 and in right there is n2, or vice versa
    // which means this is our current root is our common ancestor, return that
    if (left != NULL && right != NULL)
        return root;
    // if both give null, that means we didn't find n1, n2, return null
    if (left == NULL && right == NULL)
        return NULL;
    // if right returns null, recurse down left subtree, meaning there is node down the left subtree where we can find our common ancestor
    if (left != NULL)
        return leastCommonAncestor(root->left, n1, n2);
    // same for right case
    return leastCommonAncestor(root->right, n1, n2);
}
// distance finder between ancestor to given node
int findDistance(Node *root, int nodeValue, int distance)
{
    if (root == NULL)
        return -1;
    // if equal to node's value, this is the node we are trying to reach from LCA, return the distance
    if (root->data == nodeValue)
        return distance;
    // go down one level increasing distance by 1
    int left = findDistance(root->left, nodeValue, distance + 1);
    // in case we didn't return -1, meaning we found that node in left subtree we return left
    if (left != -1)
        return left;
    // else do it for right
    return findDistance(root->right, nodeValue, distance + 1);
}
// main function for our need
int distanceBetween(Node *root, int n1, int n2)
{
    Node *commonAncestor = leastCommonAncestor(root, n1, n2);
    // find distance between that node to its common ancestor, for both nodes
    int distanceOne = findDistance(commonAncestor, n1, 0);
    int distanceTwo = findDistance(commonAncestor, n2, 0);
    return distanceOne + distanceTwo;
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

    cout << distanceBetween(root, 4, 6);
}