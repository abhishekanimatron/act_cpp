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

// Input:
// 7 7
// 1 2
// 1 3
// 2 4
// 2 5
// 2 6
// 2 7
// 3 7
//output:
//for preorder
// 1
// 2
// 4
// 5
// 6
// 7
// 3
//for postorder
// 4
// 5
// 6
// 3
// 7
// 2
// 1

// dfs traversal
//visited array
const int N = 1000;
bool visi[N];
VI adj[N]; //adjacency list
//as accessed in functions so declared globally

void dfs(int node)
{
    //for preorder
    // O(node);
    visi[node] = true; //make node visited
    VI::iterator it;
    // for each children node of current node
    FOREACH(it, adj[node])
    {
        // if not visited, call for dfs in this too
        if (!visi[*it])
        {
            dfs(*it);
        }
    }
    //for postorder
    O(node);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // initialize visited with zeros
    FOR(i, 0, N, 1)
    {
        visi[i] = 0;
    }

    int n, m; //vertices, edges
    cin >> n >> m;
    //take edges
    int x, y;
    FOR(i, 0, m, 1)
    {
        cin >> x >> y;
        adj[x].PB(y);
        adj[y].PB(x);
    }
    dfs(1); //first node pushed
    return 0;
}
