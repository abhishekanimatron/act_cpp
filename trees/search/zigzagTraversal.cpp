#include <iostream>
#include <stack>
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

// ---->
// <----
// ----->
// <----
void zigzagPrinter(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    // create stacks for
    // contains current nodes //which is printed
    stack<Node *> currentLevel;
    // child nodes //for next traversal
    stack<Node *> nextLevel;
    // a boolean variable telling if we are printing from left to right or right to left
    bool leftToRight = true;
    // push the root node to current stack
    currentLevel.push(root);

    // loop till stack is empty
    while (!currentLevel.empty())
    {
        // store top node in temp
        Node *temp = currentLevel.top();
        currentLevel.pop();

        if (temp)
        {
            // if temp node exists print it
            cout << temp->data << " ";
            //  if direction is left to right
            if (leftToRight)
            {
                // push temp node's left child, if it exists
                if (temp->left)
                    nextLevel.push(temp->left);
                //  then right child
                if (temp->right)
                    nextLevel.push(temp->right);
            }
            //  if direction is right to left
            else
            {
                // push temp node's right child, if it exists
                if (temp->right)
                    nextLevel.push(temp->right);
                // then left child
                if (temp->left)
                    nextLevel.push(temp->left);
            }
        }
        // if there are nodes in current level
        if (currentLevel.empty())
        {
            // toggle direction
            leftToRight = !leftToRight;
            // swap the items in next level to current level
            swap(currentLevel, nextLevel);
        }
    }
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
    //  1 3 2 4 5 6 7
    // 1
    // 3 2
    // 4 5 6 7
    zigzagPrinter(root);
}