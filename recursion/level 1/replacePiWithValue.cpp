#include <iostream>
#include <string>
using namespace std;

void piValue(string s)
{
    if (s.length() == 0)
    {
        return;
    }

    if (s[0] == 'p' && s[1] == 'i')
    {
        cout << "3.14";
        piValue(s.substr(2));
    }
    else
    {
        cout << s[0];
        piValue(s.substr(1));
    }
}

int main()
{
    string s;
    cin >> s;
    piValue(s);
    //input: okaypinopi
    //output: okay3.14no3.14

    //dry run
    // okaypinopi
    // kaypinopi //o printed
    // aypinopi
    // ypinopi
    // pinopi
    // nopi //3.14 printed
    // opi
    // pi
    // //3.14 printed
}