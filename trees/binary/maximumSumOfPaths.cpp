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

int maximumPathSumHelper(Node *root, int &answer)
{
    if (root == NULL)
        return 0;
    // sum from left and right subtrees
    int leftSum = maximumPathSumHelper(root->left, answer);
    int rightSum = maximumPathSumHelper(root->right, answer);
    // maximum for current node
    //considers cuurent value, value +left and right sum, value +left, value +right
    int nodeMaximum = max(max(root->data, root->data + leftSum + rightSum), max(root->data + leftSum, root->data + rightSum));

    // change answer
    answer = max(nodeMaximum, answer);
    int singlePathSum = max(root->data, max(root->data + leftSum, root->data + rightSum));
    return singlePathSum;
}

int maximumPathSum(Node *root)
{
    int answer = INT_MIN;
    maximumPathSumHelper(root, answer);
    return answer;
}
int main()
{ //      tree:
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
    cout << maximumPathSum(root) << "\n";
}