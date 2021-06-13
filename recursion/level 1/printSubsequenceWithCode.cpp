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
    int code = c;

    // in one branch we don't include this character and in one we do
    printSubsequences(s.substr(1), subsequence);
    printSubsequences(s.substr(1), subsequence + c);
    printSubsequences(s.substr(1), subsequence + to_string(code));
}

int main()
{
    string s = "ab";
    printSubsequences(s, "");
    //output:
    //
    // b
    // 98
    // a
    // ab
    // a98
    // 97
    // 97b
    // 9798
}