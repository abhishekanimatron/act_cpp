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

// inserts into bst
Node *insert(Node *root, int value)
{
    if (root == NULL)
    {
        return new Node(value);
    }
    if (root->data < value)
    {
        root->right = insert(root->right, value);
    }
    else
        root->left = insert(root->left, value);
    return root;
}

void inOrderTraversal(struct Node *root)
{
    if (root == NULL)
        return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// returns the inorder successor for the passed node
Node *inorderSuccessor(Node *root)
{
    // store passed node to current
    Node *current = root;
    // loop till current's left is null, which will get as greatest from left subtree
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// returns root of the tree with target node being deleted
Node *deletion(Node *root, int target)
{
    // if target is less than root's data, delete that in left subtree and attach the rest of left subtree to root
    if (target < root->data)
        root->left = deletion(root->left, target);
    // similarly, call for right subtree if it's greater than root's value
    else if (target > root->data)
        root->right = deletion(root->right, target);
    // if this node is our target node
    // CASE 1 and CASE 2
    else
    {
        // if the left child is NULL
        if (root->left == NULL)
        {
            // store the right subtree
            Node *temp = root->right;
            // delete this node
            free(root);
            // return the right subtree, which will attached to the node previous to deleted node, by recursive call
            return temp;
        }
        // if the right child is NULL
        else if (root->right == NULL)
        {
            // store the left subtree
            Node *temp = root->left;
            // delete this node
            free(root);
            // return the left subtree, which will attached to the node previous to deleted node, by recursive call
            return temp;
        }
        // CASE 3
        // we find the least node in right subtree
        Node *temp = inorderSuccessor(root->right);
        // we replace this node's data with temp's data, which is just bigger than this one
        root->data = temp->data;
        // now the successor data is needed to be deleted, which resides in our right subtree
        // so we call delete for right subtree, for temp's data which is the successor
        root->right = deletion(root->right, temp->data);
    }
    // and return root which is modified tree, with deleted target node
    return root;
}

int main()
{
    //     1
    // 2       4
    //             9
    //         7       12

    Node *root = new Node(1);
    insert(root, 4);
    insert(root, 9);
    insert(root, 12);
    insert(root, 2);
    insert(root, 7);

    inOrderTraversal(root);
    deletion(root, 9);
    cout << "\n";
    inOrderTraversal(root);
}