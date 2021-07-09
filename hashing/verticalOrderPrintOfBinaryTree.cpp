#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define PI 3.1415926535897932384626433832795

typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;

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

void verticalOrder(Node *root, int hDis, map<int, VI> &m)
{
    if (root == NULL)
        return;
    // push the value of node, in that distance's key
    m[hDis].push_back(root->data);
    // call for children
    verticalOrder(root->left, hDis - 1, m);
    verticalOrder(root->right, hDis + 1, m);
}

int main()
{
    //      tree:
    /*
                1
               / \
              2   3
            /  \ / \
           4   5/   \   
               6     7
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    map<int, VI> m;
    int hDis = 0; //horizontal distance
    verticalOrder(root, hDis, m);
    map<int, VI>::iterator it;

    FOREACH(it, m)
    {
        FOR(i, 0, (it->SS).size(), 1)
        {
            cout << (it->SS)[i] << " ";
        }
        cout << "\n";
    }
    // 4
    // 2
    // 1 5 6
    // 3
    // 7
    return 0;
}