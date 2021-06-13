#include <iostream>
#include <string>
using namespace std;

void reverseString(string s)
{
    if (s.length() == 0)
    {
        return;
    }

    string restOfString = s.substr(1);
    reverseString(restOfString);
    cout << s[0];
}

int main()
{
    string s;
    cin >> s;
    reverseString(s);
    //input: gas
    //output: sag

    //dry run
    // sag
    // ag
    // g
}