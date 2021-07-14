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

#define O(i) cout << i << "\n"
#define AI(a, i) cin >> a[i]
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
typedef unordered_map<int, int> UMPII;
typedef map<int, int> MPII;
typedef set<int> SETI;

const int N = 1000;
// globals
VI parent(N); //stores parent for each vertex
VI sizee(N);  //for ds_union using size
// makes set of passed vertex
void makeSet(int v)
{
    // initially its parent will be itself
    parent[v] = v;
    sizee[v] = 1; //and size will be 1
}
// returns absolute parent of that vertex (find set which it belongs to)
int findSet(int v)
{
    // if itself is parent return that
    if (v == parent[v])
        return v;
    // else find absolute parent, parent's parent like this way
    return parent[v] = findSet(parent[v]); //path compression
}
// does union of two vertices passed
void unionSets(int a, int b)
{
    // find their parents
    a = findSet(a);
    b = findSet(b);
    // if the parents aren't the same
    if (a != b)
    {
        // if a's size is greater than b, swap(done to reduce steps)
        if (sizee[a] < sizee[b])
            swap(a, b);
        // make b's parent as a
        parent[b] = a;
        // increase a's size with that of b's size
        sizee[a] += sizee[b];
    }
}
int main()
{
    //input: 4 3
    // 0 1
    // 1 2
    // 2 3
    // No Cycle Detected.
    //input: 4 4
    // 0 1
    // 1 2
    // 2 3
    // 3 0
    // Cycle Detected.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // make set for each given vertices
    REP(i, N)
    {
        makeSet(i);
    }
    int n, m; //vertices, edges
    cin >> n >> m;
    VVI edges; //stores each edge
    REP(i, m)
    { //take edges
        int u, v;
        cin >> u >> v;
        edges.PB({u, v}); //push to edges vector
    }
    bool cycle = false; //indicator
    FOREACH(i, edges)
    //for each edge in vector "edges"
    {
        //take out edge u-->v
        int u = (*i)[0];
        int v = (*i)[1];
        //find their absolute parents
        int x = findSet(u);
        int y = findSet(v);
        if (x == y) //if they're equal, cycle is true
            cycle = true;
        else
            unionSets(u, v); //if they're not make a union of those
    }
    if (cycle)
        O("Cycle Detected.");
    else
        O("No Cycle Detected.");
    return 0;
}
