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
const int N = 1000;
VI parent(N);
VI sizee(N);

void makeSet(int v)
{
    parent[v] = v;
    sizee[v] = 1;
}

int findSet(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSets(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
    {
        if (sizee[a] < sizee[b])
            swap(a, b);
        parent[b] = a;
        sizee[a] += sizee[b];
    }
}

int main()
{
    //Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    REP(i, N)
    {
        makeSet(i);
    }
    int n, m;
    cin >> n >> m;
    VVI edges;
    REP(i, m)
    {
        int u, v, w; //u-->v and its weight
        edges.PB({w, u, v});
    }
    sort(all(edges)); //sort based on weights
    int cost = 0;
    // for each edge
    FOREACH(i, edges)
    {
        //take out values
        int w = (*i)[0];
        int u = (*i)[1];
        int v = (*i)[2];
        int x = findSet(u);
        int y = findSet(v);
        //if they lie in same set, and we include them a cycle is formed;continue
        if (x == y)
            continue;

        else
        {
            cout << u << " " << v << "\n";
            cost += w;
            unionSets(u, v);
        }
    }
    O(cost);
    return 0;
}
