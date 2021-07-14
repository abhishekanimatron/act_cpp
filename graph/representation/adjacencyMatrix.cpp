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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //n: number of vertices, m: number of edges
    int n, m;
    cin >> n >> m;
    VVI adjmat(n + 1, VI(n + 1, 0)); // 0 to n, square matrix of order n initialized with 0s
    FOR(i, 0, m, 1)
    {
        // take edges
        int x, y;
        cin >> x >> y;
        //fill the cell with 1 indicating edge between them
        adjmat[x][y] = 1;
        adjmat[y][x] = 1;
    }
    O("Adjacency Matrix:");
    O("-------------------------");
    FOR(i, 1, n + 1, 1)
    {
        FOR(j, 1, n + 1, 1)
        {
            cout << adjmat[i][j] << " ";
        }
        O(" ");
    }
    O("-------------------------");
    // Input:
    // 7 7
    // 1 2
    // 1 3
    // 2 4
    // 2 5
    // 2 6
    // 2 7
    // 3 7
    // Output:
    // Adjacency Matrix:
    // -------------------------
    // 0 1 1 0 0 0 0
    // 1 0 0 1 1 1 1
    // 1 0 0 0 0 0 1
    // 0 1 0 0 0 0 0
    // 0 1 0 0 0 0 0
    // 0 1 0 0 0 0 0
    // 0 1 1 0 0 0 0
    // -------------------------

    return 0;
}
