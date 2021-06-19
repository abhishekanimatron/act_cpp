#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s = "((a+b)+c)"; //0
    // string s = "((a+b))"; //1
    stack<char> stac;
    bool answer = false;
    for (int i = 0; i < s.length(); i++)
    {
        // operators and brackets are pushed to stack
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(')
            stac.push(s[i]);
        //if closing bracket is there
        else if (s[i] == ')')
        {
            //if there is opening bracket before operator, means brackets don't perform any operation inside, so redundant
            if (stac.top() == '(')
                answer = true;
            // pop the operators of stack (all of them)
            while (stac.top() == '+' || stac.top() == '-' || stac.top() == '*' || stac.top() == '/')
                stac.pop();
            //pop the opening bracket for this closing one
            stac.pop();
        }
    }
    cout << answer << endl;
}