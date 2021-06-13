#include <iostream>
#include <string>
using namespace std;

string placeX(string s)
{
    if (s.length() == 0)
    {
        return "";
    }
    // store the 'x' of above passed string in c
    char c = s[0];
    // store rest of string, calling that recursively
    string restOfString = placeX(s.substr(1));

    if (c == 'x')
    {
        // if equal return restofstring with x (c, here) at the end
        return restOfString + c;
    }
    // if not equal return full string with that character (which is not x) at starting
    return (c + restOfString);
}

int main()
{
    string s = "aaxhivxnn";
    cout << placeX(s) << endl;
    //output: aahivnnxx
}