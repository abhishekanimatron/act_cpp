#include <iostream>
#include <queue>
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

//print and recurse for L & R, if null return
void preOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

//recurse L, print and recurse for R, if null return
void inOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// recurse for L & R, print, if null return
void postOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    // queue will store our nodes to look for
    queue<Node *> q;
    q.push(root); //push our root
    q.push(NULL); //push NULL, which tells the level print for this level (current level) is over

    while (!q.empty())
    {
        // front, leftmost part of queue
        Node *node = q.front();
        q.pop(); // pop this node from queue
        // if that is not a null
        if (node != NULL)
        {
            // print that node
            cout << node->data << " ";
            //if that node has a left child, push it to queue
            if (node->left != NULL)
                q.push(node->left);
            if (node->right != NULL)
                q.push(node->right);
        }
        // node is null, and queue has more elements, which are of sub levels, so we push a null to the queue
        else if (!q.empty()) //if queue is not empty after popping that node
            q.push(NULL);
    }
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    //      tree:
    //           1
    //     2          3
    //   4   5      6   7

    preOrderTraversal(root);
    // 1 2 4 5 3 6 7
    cout << endl;
    inOrderTraversal(root);
    // 4 2 5 1 6 3 7
    cout << endl;
    postOrderTraversal(root);
    // 4 5 2 6 7 3 1
    cout << endl;
    levelOrderTraversal(root);
    // 1 2 3 4 5 6 7
    cout << endl;
}