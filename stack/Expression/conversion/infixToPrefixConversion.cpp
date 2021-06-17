#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// returns precenden rank of an operator
int precedencer(char c)
{
    if (c == '^')
        return 3;
    if (c == '/' || c == '*')
        return 2;
    if (c == '-' || c == '+')
        return 1;
    else
        return -1;
}

string infixToPrefix(string s)
{
    // reverse string
    reverse(s.begin(), s.end());
    stack<char> stac;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        //if operatand add to result
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];
        else if (s[i] == ')')
            stac.push(s[i]);
        else if (s[i] == '(')
        {
            while (!stac.empty() && stac.top() != ')')
            {
                res += stac.top();
                stac.pop();
            }
            // pop opening bracket
            if (!stac.empty())
                stac.pop();
        }
        else
        {
            // for operator
            while (!stac.empty() && precedencer(stac.top()) >= precedencer(s[i]))
            {
                res += stac.top();
                stac.pop();
            }
            stac.push(s[i]);
        }
    }
    while (!stac.empty())
    {
        res += stac.top();
        stac.pop();
    }

    //reverse the answer
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    cout << infixToPrefix("(a-b/c)*(a/k-l)") << endl;
    // *-a/bc-/akl
}