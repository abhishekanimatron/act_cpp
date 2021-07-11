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

struct Item
{
    int value, weight;
    Item(int value, int weight)
    {
        this->value = value;
        this->weight = weight;
    }
};

bool compare(Item a, Item b)
{
    // compare based on larger value per weight rate
    double rate1 = (double)a.value / (double)a.weight;
    double rate2 = (double)b.value / (double)b.weight;
    return rate1 > rate2;
}
double fractionalKnapsack(int W, Item arr[], int n)
{
    // sort based on rate, descending order
    sort(arr, arr + n, compare);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i].value << "  " << arr[i].weight << " : " << ((double)arr[i].value / arr[i].weight) << endl;
    // }
    int currentWeight = 0;
    double finalValue = 0.0; //value of sack
    FOR(i, 0, n, 1)
    {
        // add if no overflow, (add whole)
        if (currentWeight + arr[i].weight <= W)
        {
            currentWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        {
            int remaining = W - currentWeight; //remaining weight in sack
            // else add fractional part's value
            finalValue += arr[i].value * ((double)remaining / (double)arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int W = 50; //    Weight of knapsack
    Item arr[] = {{60, 10}, {100, 20}, {120, 30}};

    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
    return 0;
    // Maximum value we can obtain = 240
}
