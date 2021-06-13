#include <iostream>
using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void keyfunction(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }
    char c = s[0];
    string code = keypad[c - '0'];
    string restOfString = s.substr(1);

    for (int i = 0; i < code.length(); i++)
    {
        keyfunction(restOfString, ans + code[i]);
    }
}

//dry run
//input:3
//c=3
// code=def
// rest=0
// for i to 3 //code length
// func(0, ""+ d)
// if(true) => print d
// return
// loop and print e,f

int main()
{
    keyfunction("34", "");
    // output:
    // dg
    // dh
    // di
    // eg
    // eh
    // ei
    // fg
    // fh
    // fi
}