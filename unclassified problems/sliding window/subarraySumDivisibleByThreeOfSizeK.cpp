#include <iostream>
#include <vector>
using namespace std;

void numbers(vector<int> arr, int k)
{
    // stores pair of indexes, start and end of which it is divisible by 3
    pair<int, int> ans;
    int sum = 0;
    // calculate sum of first set of numbers of size "ofSize"
    for (int i = 0; i < k; i++)
        sum += arr[i];
    // boolean to store if the such number exists in the vector
    bool found = false;
    // see if our first sum is itself divisible or not
    if (sum % 3 == 0)
    {
        // as sum of digits are divisible by 3, thus the number is divisible by 3, so store the first index and end index in the answer pair
        ans = make_pair(0, k - 1);
        found = true;
    }
    // traverse from index of right of previous window, till end of vector is reached
    for (int j = k; j < arr.size(); j++)
    {
        // if answer is found (true) break out of loop
        if (found)
            break;
        // add rightmost element and decrease leftmost of window, making a new window in right direction
        sum = sum + arr[j] - arr[j - k];
        // if sum is divisible
        if (sum % 3 == 0)
        { //make pair of start and end index of window, and update found
            ans = make_pair(j - k + 1, j);
            found = true;
        }
    }
    // if no such set of number exists, make first index to -1, signaling, invalid index
    if (!found)
        ans = make_pair(-1, 0);
    // show message if index is invalid
    if (ans.first == -1)
        cout << "No such set of numbers exist.\n";
    else
    {
        // else print the numbers form start till end index in the window stored in answer
        for (int i = ans.first; i <= ans.second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    vector<int> v = {84, 23, 45, 12, 56, 82};
    int ofSize = 3;
    numbers(v, ofSize);
}