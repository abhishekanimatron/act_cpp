#include <iostream>
#include <stack>
using namespace std;

// returns precedence of character
int precedencer(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    return -1;
}

string infixToPostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        // opernand, simply add to result
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
            res += s[i];
        // if opening bracket push to stack
        else if (s[i] == '(')
            st.push(s[i]);
        // if closing bracket
        else if (s[i] == ')')
        {
            // travere till opening is found
            while (!st.empty() && st.top() != '(')
            {
                //append stack's top value
                res += st.top();
                st.pop();
            }
            // to pop opening bracket
            if (!st.empty())
                st.pop();
        }
        // for operators
        else
        {
            // pop until our current element is having smaller precendence then stack's top
            while (!st.empty() && precedencer(st.top()) >= precedencer(s[i]))
            {
                res += st.top();
                st.pop();
            }
            // push current operator
            st.push(s[i]);
        }
    }
    // append rest
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    return res;
}

int main()
{
    cout << infixToPostfix("(a-b/c)*(a/k-l)") << endl;
    // abc/-ak/l-*
}