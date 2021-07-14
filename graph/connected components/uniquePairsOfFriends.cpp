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

int getComp(int index, VVI &adj, vector<bool> &visited)
{
    // if already visited return zero
    if (visited[index])
        return 0;
    visited[index] = true; //make it visited
    int ans = 1;           //intialize answer with 1 for this component
    // for each subsequent vertices of this vertex
    for (auto i : adj[index])
    {
        // if this vertex is not visited, add answer of subsequent calls to this vertex's answer
        if (!visited[i])
        {
            ans += getComp(i, adj, visited);
            visited[i] = true; // make this vertex visited
        }
    }
    return ans;
}

int main()
{
    // input: 5 3
    // 0 1
    // 2 3
    // 0 4
    // Number of ways:
    // 6

    //explanation:
    //number of components: 2
    // 0 1 4 && 2 3
    //ways will be:
    /*
        0 2
        0 3
        1 2 
        1 3
        4 2
        4 3
    */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; //vertices, edges
    cin >> n >> m;
    VVI adj(n);                 //adjacency list
    vector<bool> visited(n, 0); //visited array
    //take edges
    FOR(i, 0, m, 1)
    {
        int u, v;
        cin >> u >> v;
        adj[u].PB(v);
        adj[v].PB(u);
    }
    //components vector
    VI components;
    //for each vertex
    FOR(i, 0, n, 1)
    {
        //if not visited
        if (!visited[i])
        {
            components.PB(getComp(i, adj, visited));
        }
    }

    long long ans = 0;
    for (auto i : components)
    {
        ans += i * (n - i);
    }
    O("Number of ways:");
    O(ans / 2);

    return 0;
}
