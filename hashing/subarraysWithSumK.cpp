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
    int n, k;
    cin >> n >> k;
    VI a(n);
    FOR(i, 0, n, 1)
    {
        AI(a, i);
    }
    UMPII um;
    int currentSum = 0;
    int ans = 0;
    int i = 0;
    while (i < n)
    {
        currentSum += a[i];
        // if current sum is k, add it to ans
        if (currentSum == k)
            ans += 1;
        // if current sum - k is present in map, that means subarray with sum k is there
        if (um.find(currentSum - k) != um.end())
            // add its count to answer
            ans += um[currentSum - k];
        um[currentSum]++;
        i++;
    }
    O(ans);
    //input:
    // 4
    // 0
    // output
    // 1 -1 1 -1
    // 4
    return 0;
}
