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

    int n;
    cin >> n;
    VI a(n);

    FOR(i, 0, n, 1)
    {
        AI(a, i);
    }
    // create min heap, (asending order sort)
    priority_queue<int, VI, greater<int>> minHeap;
    // insert elements to heap
    FOR(i, 0, n, 1)
    {
        minHeap.push(a[i]);
    }
    int ans = 0; //intial computation time is 0
    // till heap's size is only 1, that is only 1 file is there which is merged version of all files
    while (minHeap.size() > 1)
    {
        int file1 = minHeap.top();
        minHeap.pop();
        int file2 = minHeap.top();
        minHeap.pop();
        //add the computation time to merge the files to the answer
        ans += file1 + file2;
        //push the merged file(computation time) to heap
        minHeap.push(file1 + file2);
    }
    O(ans);

    // input:4
    // output:
    // 2 7 4 5
    // 35
    return 0;
}
