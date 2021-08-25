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
//globals
int n, m;
const int N = 1000;
VVI g[N]; //adjacency list
VI disstance(N);
VI parent(N);
vector<bool> visited(N);

void primsMST(int source, int &cost)
{
    // set distance for each vertex to maximum
    REP(i, n)
    {
        disstance[i] = INT16_MAX;
    }

    // set like {distance,vertex}
    set<VI> s;
    // set distance of current source to 0
    disstance[source] = 0;
    s.insert({0, source});
    // while set isn't empty
    while (!s.empty())
    {
        auto x = *(s.begin()); //first element of set
        s.erase(x);            //delete it from set
        visited[x[1]] = true;  //make the vertex as visited
        int u = x[1];
        int v = parent[x[1]];
        int w = x[0];
        cout << u << " " << v << " " << w << "\n";
        cost += w;
        // for each connected to this vertex
        for (auto it : g[x[1]])
        {
            // if it is already visited, continue
            if (visited[it[0]])
                continue;
            // if current distance is greater than weight rn,
            if (disstance[it[0]] > it[1])
            //update it
            {
                //erase the previous distance set element
                s.erase({disstance[it[0]], it[0]});
                //change distance to this, which is lesser
                disstance[it[0]] = it[1];
                // insert new set element with updated value
                s.insert({disstance[it[0]], it[0]});
                // make x[1] its new parent
                parent[it[0]] = x[1];
            }
        }
    }
}
int main()
{
    /*
    input:
    4 5
    0 1 10
    1 2 15
    0 2 5
    3 1 2
    3 2 40
    output:
    0 0 0
    2 0 5
    1 0 10
    3 1 2
    Cost:
    17
    */

    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    REP(i, m)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].PB({v, w});
        g[v].PB({u, w});
    }
    int cost = 0;
    primsMST(0, cost);
    O("Cost:");
    O(cost);
    return 0;
}
