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

struct compare
{

    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // if frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;

        // insert elements in the priority queue on the basis of
        // decreasing order of frequencies
        return p1.second < p2.second;
    }
};

void print_K_mostFrequentNumber(int arr[], int n, int k)
{
    UMPII um;
    FOR(i, 0, n, 1)
    {
        um[arr[i]]++;
    }
    // priority queue 'pq' implemented as max heap on the basis
    // of the comparison operator 'compare'
    // element with the highest frequency is the root of 'pq'
    // in case of conflicts, larger element is the root
    priority_queue<PII, VII, compare> pq(um.begin(), um.end());
    FOR(i, 0, k, 1)
    {
        cout << pq.top().first << " ";
        pq.pop();
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = 8;
    int k = 2;
    print_K_mostFrequentNumber(arr, n, k);
    return 0;
}
