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

// All denominations of Indian Currency
int deno[] = {1, 2, 5, 10, 20,
              50, 100, 500, 1000};
int n = sizeof(deno) / sizeof(deno[0]);
void findMin(int Price)
{
    sort(deno, deno + n);
    vector<int> ans; //stores coins needed to make n
    RFOR(i, n - 1, 0, 1)
    { //check from biggest coin value
        // if price is greater than coin value
        while (Price >= deno[i])
        {
            // add it
            Price -= deno[i];
            //push this coin to answer
            ans.PB(deno[i]);
        }
    }
    cout << "\n";
    FOR(i, 0, ans.size(), 1)
    {
        O(ans[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 93;
    cout << "Following is minimal"
         << " number of change for " << n
         << ": ";
    findMin(n);
    // 50
    // 20
    // 20
    // 2
    // 1
    return 0;
}
