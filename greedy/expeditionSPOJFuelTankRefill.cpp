// A group of cows grabbed a truck and ventured on an expedition deep into the jungle. Being rather poor drivers, the cows unfortunately managed to run over a rock and puncture the truck's fuel tank. The truck now leaks one unit of fuel every unit of distance it travels.

// To repair the truck, the cows need to drive to the nearest town (no more than 1,000,000 units distant) down a long, winding road. On this road, between the town and the current location of the truck, there are N (1 <= N <= 10,000) fuel stops where the cows can stop to acquire additional fuel (1..100 units at each stop).

// The jungle is a dangerous place for humans and is especially dangerous for cows. Therefore, the cows want to make the minimum possible number of stops for fuel on the way to the town. Fortunately, the capacity of the fuel tank on their truck is so large that there is effectively no limit to the amount of fuel it can hold. The truck is currently L units away from the town and has P units of fuel (1 <= P <= 1,000,000).

// Determine the minimum number of stops needed to reach the town, or if the cows cannot reach the town at all.
// * Input
// Line 1: A single integer, N
// Lines 2..N+1: Each line contains two space-separated integers describing a fuel stop: The first integer is the distance from the town to the stop; the second is the amount of fuel available at that stop.
// Line N+2: Two space-separated integers, L and P
// * Output
//  Output a single integer giving the minimum number of fuel stops necessary to reach the town. If it is not possible to reach the town, output -1.

//? Example
// Input :
// 4
// 4 4
// 5 2
// 11 5
// 15 10
// 25 10

// Output:
// 2

// Input details
// The truck is 25 units away from the town; the truck has 10 units
// of fuel.  Along the road, there are 4 fuel stops at distances 4,
// 5, 11, and 15 from the town (so these are initially at distances
// 21, 20, 14, and 10 from the truck).  These fuel stops can supply
// up to 4, 2, 5, and 10 units of fuel, respectively.

// Output details:
// Drive 10 units, stop to acquire 10 more units of fuel, drive 4 more
// units, stop to acquire 5 more units of fuel, then drive to the town.

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

    //number of stops
    int n;
    cin >> n;
    // vector of pairs of distance of stops from town, and fuel given in that stop
    VII a(n);
    FOR(i, 0, n, 1)
    {
        cin >> a[i].first >> a[i].second;
    }
    // L units away from town, P units of fuel in tank
    int l, p;
    cin >> l >> p;
    // replace distance of stops from town to distance of stops from truck's current position
    FOR(i, 0, n, 1)
    {
        a[i].first = l - a[i].first;
    }
    // sort on basis of distance from truck
    sort(a.begin(), a.end());
    int ans = 0;                  //number of stops taken
    int current = p;              //current fuel
    priority_queue<int, VI> pque; //this queue, max heap (descending order) stores fuels given in each stop
    bool flag = 0;                //flag to indicate if its possible to reach town or not, (1 if not possible)
    FOR(i, 0, n, 1)
    {
        // if current fuel is greater than equal to required (to go to town)
        if (current >= l)
            break;
        // loop till current fuel is lesser than distance of next fuel stop
        while (current < a[i].first)
        {
            // if the queue has no more extra fuel, flag it 1
            if (pque.empty())
            {
                flag = 1;
                break;
            }
            ans++;
            // add the maximum fuel available
            current += pque.top();
            pque.pop(); // and pop that fuel value
        }
        //if flag is true break out of loop
        if (flag)
            break;
        //else
        // push current fuel stop's value to queue
        pque.push(a[i].second);
    }
    if (flag)
    {
        O("NOT POSSIBLE");
        // indicating it's not possible to reach town
        O("-1");
    }
    // to reach town
    while (!pque.empty() && current < l)
    {
        // add the maximum fuel available
        current += pque.top();
        pque.pop(); // and pop that fuel value
        ans++;
    }
    if (current < l)
    {
        O("NOT POSSIBLE");
        O("-1");
    }
    O("---------------------");
    O("REQUIRED STOPS");
    O(ans);
    return 0;
}
