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
#define ALL(cont) cont.begin(), cont.end()
#define RALL(cont) cont.end(), cont.begin()
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
    int n;
    cin >> n;
    VI a(n);
    FOR(i, 0, n, 1)
    {
        AI(a, i);
    }
    sort(ALL(a));
    long long minimum = 0, maximum = 0;
    FOR(i, 0, n / 2, 1)
    {
        // to get maximum difference, subtract mid from 0, and increment both one by one
        maximum += (a[i + n / 2] - a[i]);
        // to get minimum difference, subtract adjacent elements(odd - even) and increment both one by one
        minimum += (a[2 * i + 1] - a[2 * i]);
    }
    O("--------------");
    O("minimum");
    O(minimum);
    O("maximum");
    O(maximum);
    return 0;
    // 4
    // 12 -3 10 0
    // --------------
    // minimum
    // 5
    // maximum
    // 25
}
