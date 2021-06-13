#include <iostream>
#include <string>
using namespace std;

void printSubsequences(string s, string subsequence = "")
{
    if (s.length() == 0)
    {
        cout << subsequence << endl;
        return;
    }
    //we store our first character in a variable
    char c = s[0];

    // in one branch we don't include this character and in one we do
    printSubsequences(s.substr(1), subsequence);
    printSubsequences(s.substr(1), subsequence + c);
}

int main()
{
    string s = "abc";
    printSubsequences(s, "");
    //output:
    //
    // c
    // b
    // bc
    // a
    // ac
    // ab
    // abc
}