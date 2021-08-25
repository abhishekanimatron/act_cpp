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

int main()
{
    // input:4 3
    //output:
    // 0 1
    // 1 2
    // 2 3
    // 0 1 2 3
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; //vertices,edges
    cin >> n >> m;
    int count = 0;
    VVI adj(n);        //adjacency list
    VI indegree(n, 0); //indegree with zeroes
    FOR(i, 0, m, 1)
    {
        int u, v;
        cin >> u >> v;
        // u->v is the edge, so indegree of v increases
        adj[u].PB(v);
        indegree[v]++;
    }
    queue<int> q;
    // for each vertex, if it's indegree is 0 push to queue
    FOR(i, 0, n, 1)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        // till queue is not empty print the front node
        count++;
        int x = q.front();
        q.pop();
        cout << x << " ";
        // for each next node of x
        // x-->v
        // reduce its indegree and push to queue if becomes zero
        for (auto i : adj[x])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return 0;
}
