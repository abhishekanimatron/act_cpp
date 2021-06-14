// Given an array nums of distinct integers, print all the possible permutations.
// ! You are at index idx, try out all the possible swap, Ensuring that you don’t produce
// duplicates.

// input:
// 3
// 1 2 3

// output:
// 1 2 3
// 1 3 2
// 2 1 3
// 2 3 1
// 3 2 1
// 3 1 2

#include <iostream>
#include <vector>
#include <algorithm> //for stl trick part
using namespace std;

// global ans vector declaration for ease
vector<vector<int>> ans;

// this vector takes a vector as reference and starting index
void permute(vector<int> &v, int index)
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
        // we swap current index with i's that is with the numbers following the current index number
        swap(v[i], v[index]);
        // then we call recursively for next index
        permute(v, index + 1);
        // swap again to restore original array
        swap(v[i], v[index]);
    }
    return;
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
    permute(v, 0);

    // // stl trick part
    // sort(v.begin(), v.end());
    // do
    // {
    //     ans.push_back(v);
    // } while (next_permutation(v.begin(), v.end()));

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