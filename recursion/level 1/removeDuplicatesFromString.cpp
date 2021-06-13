#include <iostream>
#include <string>
using namespace std;

string removeDuplicates(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    // store the first character of above passed string
    char c = s[0];
    // store rest of string, calling that recursively
    string restOfString = removeDuplicates(s.substr(1));

    if (c == restOfString[0])
    {
        // if equal return restofstring, i.e. skipping the equal character stores in c
        return restOfString;
    }
    // if not equal return full string with c at starting
    return (c + restOfString);
}

int main()
{
    string s = "aaaabbbbcccccddddd";
    cout << removeDuplicates(s) << endl;
    //output: abcd
}