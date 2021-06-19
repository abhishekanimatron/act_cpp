#include <iostream>
#include <stack>
#include <vector>
using namespace std;

//brute force
// Span value of first day is always 1
//     S[0] = 1;

// Calculate span value of remaining days
// by linearly checking previous days
//     for (int i = 1; i < n; i++)
//     {
//         S[i] = 1; // Initialize span value

// Traverse left while the next element
// on left is smaller than price[i]
//         for (int j = i - 1; (j >= 0) && (price[i] >= price[j]); j--)
//             S[i]++;
//     }

//stack based

vector<int> stockSpan(vector<int> stockPrices)
{
    vector<int> answer;
    // storing price of that stock and span as a pair in stack
    stack<pair<int, int>> stac;
    for (auto price : stockPrices)
    {
        // considering that day itself
        int days = 1;
        while (!stac.empty() && stac.top().first <= price)
        {
            // second stores the span, which we add to our current stock's span
            days += stac.top().second;
            stac.pop();
        }
        // push price and days as pair
        stac.push({price, days});
        // push days in answer vector
        answer.push_back(days);
    }
    return answer;
}

int main()
{
    vector<int> stockPrices = {100, 80, 60, 70, 60, 75, 85};
    vector<int> spans = stockSpan(stockPrices);
    for (auto i : spans)
        cout << i << " ";
    // 1 1 1 2 1 4 6

    cout << endl;
}