#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

bool identical(Node *root1, Node *root2)
{
    // if both node is null, it is identical
    if (root1 == NULL && root2 == NULL)
        return true;
    // if anyone is null but not the other one, it isn't identical, return false
    else if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        // check if they have same values
        bool dataSame = root1->data == root2->data;
        // check for each subtrees
        bool leftSame = identical(root1->left, root2->left);
        bool rightSame = identical(root1->right, root2->right);

        // if all 3 are satisfied, it's identical, return true
        if (dataSame && leftSame && rightSame)
            return true;
        // else return false
        return false;
    }
}

int main()
{

    //      tree:
    //           1
    //         /   \
    //        2     3
    //      /  \   /
    //     4   5  6
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    //      tree:
    //           1
    //         /   \
    //        2     3
    //      /  \   /  \
    //     4   5  6    7
    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    if (identical(root, root2))
        cout << "They are identical Binary Search Trees.\n";
    else
        cout << "They are not identical Binary Search Trees.\n";
}