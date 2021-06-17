#include <iostream>
#include <stack>
using namespace std;

void reverseSentence(string s)
{
    stack<string> stac;
    for (int i = 0; i < s.length(); i++)
    {
        string word = "";
        //loop until either a space or end is there, upto that is a word
        while (s[i] != ' ' && i < s.length())
        {
            word += s[i];
            i++;
        }
        // push word to the stack
        // cout << "i: " << i << endl;
        stac.push(word);
    }
    while (!stac.empty())
    {
        cout << stac.top() << " ";
        stac.pop();
    }
    cout << endl;
}
int main()
{
    string s = "hi one two three";
    reverseSentence(s);
    //three two one hi
}