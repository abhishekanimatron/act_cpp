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

bool isCycle(int current, VVI &adj, vector<bool> &visited, VI &seen)
{
    seen[current] = true; //make it seen

    // if this vertex is not visited already
    if (!visited[current])
    {
        visited[current] = true; //make it visited
        for (auto i : adj[current])
        {

            // if its not already visited and subsequent call returns true, return true
            if (!visited[i] && isCycle(i, adj, visited, seen))
                return true;
            if (seen[i]) //if already seen
                return true;
        }
    }
    seen[current] = false; //again make it unseen
    return false;
}

int main()
{
    // input: 4 3
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
        // u-->v
        adj[u].PB(v);
    }
    bool cycle = false;         //indicator
    VI seen(n, 0);              //stack to store vertices visited with zeroes
    vector<bool> visited(n, 0); //visited array with zeroes
    // for each vertex
    FOR(i, 0, n, 1)
    {
        // for each vertex if it's not visited and cycle function returns true, there is a cycle
        if (!visited[i] && isCycle(i, adj, visited, seen))
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
