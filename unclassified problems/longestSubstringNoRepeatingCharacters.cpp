#include <iostream>
#include <vector>
using namespace std;

// pwwkew
// 3
// pwwrkew
// 4
// aaaaa
// 1

int main()
{
    string s;
    cin >> s;
    // to make a locker for each character (256 ascii), store -1 in each indicating they have not occurred yet
    vector<int> store(256, -1);
    int maximum = 0; //answer
    int start = -1;  // start of answer
    for (int i = 0; i < s.length(); i++)
    {
        // if value at that character's locker is greater than start, assign start to that value
        // meaning that character now repeats so store that index as starting point of substring
        if (store[s[i]] > start)
            start = store[s[i]];
        // index of that character is stored in locker
        store[s[i]] = i;
        //max of maximum & i - start (current index - starting of substring)
        maximum = max(maximum, i - start);
    }
    cout << maximum << endl;
}