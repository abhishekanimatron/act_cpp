#include <iostream>
#include <stack>
using namespace std;

bool balanced(string s)
{
    stack<char> stac;
    bool ans = true;

    for (int i = 0; i < s.length(); i++)
    {
        //if opening, push simply
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            stac.push(s[i]);
        //for each bracket (closing), check whether top of stack is corresponding opening
        else if (s[i] == ')')
        {
            //yes, then pop it
            if (stac.top() == '(' && !stac.empty())
                stac.pop();
            //else it is unbalanced
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == '}')
        {
            if (stac.top() == '{' && !stac.empty())
                stac.pop();
            else
            {
                ans = false;
                break;
            }
        }
        else if (s[i] == ']')
        {
            if (stac.top() == '[' && !stac.empty())
                stac.pop();
            else
            {
                ans = false;
                break;
            }
        }
    }

    //if more brackets left
    if (!stac.empty())
        return false;
    return ans;
}

int main()
{
    string s = "({([]}})";
    if (balanced(s))
        cout << "Balanced" << endl;
    else
        cout << "Unbalanced" << endl;
}