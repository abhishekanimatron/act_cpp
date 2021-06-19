#include <iostream>
#include <vector>
using namespace std;

// input:
// 5
// 2
// 1 0 0 0 1
// output:
// 3

// input:
// 5
// 3
// 1 0 0 0 1
// output:
// 5

int main()
{
    int n;
    cin >> n;
    int k; //k changes allowed
    cin >> k;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    int zeroes = 0;
    int answer = 0;
    // starting left pointer
    int i = 0;
    // traverse j till n
    for (int j = 0; j < n; j++)
    {
        // if element is 0 increase count
        if (v[j] == 0)
            zeroes++;
        // if zeroes becomes greater than limit, increase i and decrease 0 count if that was a zero
        while (zeroes > k)
        {
            if (v[i] == 0)
                zeroes--;
            i++;
        }
        answer = max(answer, j - i + 1);
    }
    cout << answer << endl;
}