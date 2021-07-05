#include <iostream>
#include <vector>
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
void preOrderTraversal(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// returns a vector of root nodes of generated trees
// takes in start and end, which is the data of node we will store
vector<Node *> constructTreesFromCatalan(int start, int end)
{
    vector<Node *> trees;
    // base case
    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        // take left and right subtrees first of this node
        vector<Node *> leftSubtrees = constructTreesFromCatalan(start, i - 1);
        vector<Node *> rightSubtrees = constructTreesFromCatalan(i + 1, end);
        // cout << "left: " << leftSubtrees.size() << "\n";
        for (int j = 0; j < leftSubtrees.size(); j++)
        {
            // store jth level's left subtree
            Node *left = leftSubtrees[j];
            for (int k = 0; k < rightSubtrees.size(); k++)
            {
                // store kth level's right subtree
                Node *right = rightSubtrees[k];
                // make a new node with i as root value
                Node *node = new Node(i);
                // attach left and right values from the loop's values of subtrees
                node->left = left;
                node->right = right;
                // after constructing push it to our "trees" vector
                trees.push_back(node);
            }
        }
    }
    return trees;
}

int main()
{
    // construct trees from data: 1, 2, 3 //range (1,3)
    vector<Node *> totalTrees = constructTreesFromCatalan(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << "th tree: ";
        preOrderTraversal(totalTrees[i]);
        cout << "\n";
    }
    // 1th tree: 1 2 3
    // 2th tree: 1 3 2
    // 3th tree: 2 1 3
    // 4th tree: 3 1 2
    // 5th tree: 3 2 1
}