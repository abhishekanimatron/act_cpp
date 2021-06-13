#include <iostream>
using namespace std;

void permutation(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        //we select each character of s one by one
        char c = s[i];
        // in rest part we select string upto that character and string after that
        string restOfString = s.substr(0, i) + s.substr(i + 1);
        // and recurse over rest adding our selcted character 'c' at end
        permutation(restOfString, ans + c);
    }
}

int main()
{
    permutation("ab", "");
    // output:
    // abc
    // acb
    // bac
    // bca
    // cab
    // cba
}