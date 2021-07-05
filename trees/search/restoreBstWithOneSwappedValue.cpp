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

void inorderPrinter(Node *root)
{
    if (root == NULL)
        return;
    inorderPrinter(root->left);
    cout << root->data << " ";
    inorderPrinter(root->right);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// takes a node, first, mid, last & previous pointers, dereference two times to get that node
void fillPointers(Node *root, Node **first, Node **mid, Node **last, Node **previous)
{
    // if null, just return back
    if (root == NULL)
        return;
    // call fill for left, then we do some calculations, then we call for right subtree (inorder like)
    fillPointers(root->left, first, mid, last, previous);
    // if there is a previous node, and its value is greater than current node's data, that means the property that inorder is in ascending sequence is violated, so if there is a violation,
    if (*previous && root->data < (*previous)->data)
    {
        // if this is the first time it is violated then
        if (!*first)
        {
            // store the bigger value which should appear afterwards in first pointer
            *first = *previous;
            // and current node to mid, which should appear before, that is these values are to be swapped
            *mid = root;
        }
        else
        {
            // this is not the first time it's been violated, so we store current node's value in last
            *last = root;
            // if there is no second violation, then this last will be NULL only
        }
    }
    // after this the current node becomes previous
    *previous = root;
    // and we call for right subtree
    fillPointers(root->right, first, mid, last, previous);
}

// restore bst with a pair of values swapped
void restore(Node *root)
{
    // node pointer to first, middle, last & previous
    Node *first, *mid, *last, *previous;
    //initialized to NULL
    first = NULL;
    mid = NULL;
    last = NULL;
    previous = NULL;

    // fills pointers with its values, pass its address, so as a reference
    fillPointers(root, &first, &mid, &last, &previous);

    // if the swapped values appear apart from each other(not adjacent) in inorder traversal, we will have both first & last pointers
    if (first && last)
    {
        // swap the values at first & last, restoring the original BST
        swap(&(first->data), &(last->data));
    }
    // if the swapped values are adjacent, the last pointer will be NULL, and first and mid will have values
    else if (first && mid)
    {
        // swap the values at first & mid, restoring the original BST
        swap(&(first->data), &(mid->data));
    }
}

int main()
{
    /*
            5
          /  \
        2     3
      /  \     \
     1    7     10
    */
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(7);
    root->right->right = new Node(10);
    inorderPrinter(root);
    cout << "\n";
    restore(root);
    inorderPrinter(root);
    cout << "\n";
    // 1 2 7 5 3 10
    // 1 2 3 5 7 10
}