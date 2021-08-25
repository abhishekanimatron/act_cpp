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

// takes current vertex, current color, color vector & bipartite boolean
void colorThis(int u, int current, VI &color, VVI &adj, vector<bool> &visited, bool &bipartite)
{
    // if this vertex is already colored and its color is different
    if (color[u] != -1 && color[u] != current)
    {
        // its not bipartite, return
        bipartite = false;
        return;
    }
    color[u] = current; //color it with color value passed
    // if already visited return
    if (visited[u])
        return;
    visited[u] = true; // else make it visited

    // for each connected node to u-->v
    FOREACH(i, adj[u])
    {
        //color that vertex
        colorThis(*i, current xor 1, color, adj, visited, bipartite);
        //equivalent to
        // if(current)? 0 : 1;
        //as 1 xor 0 = 1
        // & 1 xor 1 = 0
    }
}

int main()
{
    // input:
    // 3 3
    // 0 1
    // 1 2
    // 2 0
    // Graph is not Bipartite.
    // input:
    // 4 4
    // 0 1
    // 1 2
    // 2 3
    // 3 0
    // Graph is Bipartite.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    VVI adj(n);
    REP(i, m)
    {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    vector<bool> visited(n, false);
    // color array stores -1 initially for n vertices
    VI color(n, -1);
    bool bipartite;
    //for each vertex if its not visited color it with 0
    REP(i, n)
    {
        if (!visited[i])
        {
            colorThis(i, 0, color, adj, visited, bipartite);
        }
    }
    if (bipartite)
        O("Graph is Bipartite.");
    else
        O("Graph is not Bipartite.");

    return 0;
}
