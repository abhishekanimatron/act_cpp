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

// returns true if there is a cycle
// takes current node, adjacency list, visited array and parent node as parameters
bool isCycle(int current, VVI &adj, vector<bool> &visited, int parent)
{
    // make it visited
    visited[current] = true;
    // for each child of this node
    for (auto i : adj[current])
    {
        // if this is not its parent
        if (i != parent)
        {
            // if its already visited, return true
            if (visited[i])
                return true;
            // if its not already visited and subsequent call returns true, return true
            if (!visited[i] && isCycle(i, adj, visited, current))
                return true;
        }
    }
    // else there is no cycle; return false
    return false;
}

int main()
{
    // input:4 3
    // 0 1
    // 1 2
    // 2 0
    // Cycle Detected
    // input: 4 3
    // 0 1
    // 1 2
    // 2 3
    // No Cycle Detected
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; //vertices,edges
    cin >> n >> m;
    VVI adj(n); //adjacency list
    FOR(i, 0, m, 1)
    {
        int u, v;
        cin >> u >> v;
        // undirected, so u-->v and v-->u
        adj[u].PB(v);
        adj[v].PB(u);
    }
    bool cycle = false;             //indicator
    vector<bool> visited(n, false); //visited array with zeroes

    FOR(i, 0, n, 1)
    {
        // for each vertex if it's not visited and cycle function returns true, there is a cycle
        if (!visited[i] && isCycle(i, adj, visited, -1))
        {
            cycle = true;
        }
    }
    if (cycle)
        O("Cycle Detected");
    else
        O("No Cycle Detected");
    return 0;
}
