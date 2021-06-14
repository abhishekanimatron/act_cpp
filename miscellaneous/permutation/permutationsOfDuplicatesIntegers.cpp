// Given a collection of numbers, nums, that might contain duplicates, print all
// possible unique permutations in any order.
// ! While swapping, avoid duplicates. I.e avoid swapping the same numbers.

// input:
// 3
// 1 2 2

// output:
// 1 2 2
// 2 1 2
// 2 2 1

#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;

void helperFunction(vector<int> v, vector<vector<int>> &ans, int index)
{
    // if index is at end that means we have generated a permutation and insert that in answer vector
    if (index == v.size())
    {
        ans.push_back(v);
        return;
    }
    // for each index starting from that index to last
    for (int i = index; i < v.size(); i++)
    {
        // i!=index, means it has run one time, and values in v are same (duplicates)
        if (i != index and v[i] == v[index])
            continue;
        // we swap current index with i's that is with the numbers following the current index number
        swap(v[i], v[index]);
        // then we call recursively for next index
        helperFunction(v, ans, index + 1);
    }
}

// this vector takes returns answer vector with possible permutation
vector<vector<int>> permute(vector<int> v)
{
    // sort(v.begin(), v.end());
    vector<vector<int>> ans;
    helperFunction(v, ans, 0);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    // vector of integers with size of n
    vector<int> v(n);
    // input the vector 'v' using i
    for (auto &i : v)
        cin >> i;
    vector<vector<int>> ans = permute(v);
    // for each x in ans
    for (auto x : ans)
    {
        // for each i in x
        for (auto i : x)
        {
            //print i
            cout << i << " ";
        }
        cout << endl;
    }
}