#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
#include <stack>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define vi vector<int>
#define ff first
#define ss second
#define mii map<int, int>
#define rep(i, a, b) for (int i = a; i < b; i++)

int main()
{
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    mii frequency;
    rep(i, 0, n)
    {
        // increase the frequency of that element in map
        frequency[a[i]]++;
    }
    mii ::iterator it;
    for (it = frequency.begin(); it != frequency.end(); it++)
    {
        cout << it->ff << "=>" << it->ss << "\n";
    }
    // 6
    // 1 2 1 3 2 1
    // 1=>3
    // 2=>2
    // 3=>1
}