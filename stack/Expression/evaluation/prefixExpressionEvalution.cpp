#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int postfixEvaluation(string s)
{
    stack<int> stac;
    // from back
    for (int i = s.length(); i >= 0; i--)
    {
        // if operand push to stack
        if (s[i] >= '0' && s[i] <= '9')
        {
            stac.push(s[i] - '0');
        }
        else
        {
            // store the operands each in 1 & 2
            int operand1 = stac.top();
            stac.pop();
            int operand2 = stac.top();
            stac.pop();

            // an operator, so perform corresponding operation
            switch (s[i])
            {
            case '+':
                stac.push(operand1 + operand2);
                break;
            case '-':
                stac.push(operand1 - operand2);
                break;
            case '*':
                stac.push(operand1 * operand2);
                break;
            case '/':
                stac.push(operand1 / operand2);
                break;
            case '^':
                stac.push(pow(operand1, operand2));
                break;
            default:
                break;
            }
        }
    }
    // result is store in stack
    return stac.top();
}

int main()
{
    cout << postfixEvaluation("-+7*45+20") << endl;
    // output: 25
    // ((4*5) + 7) -2;
    // 20+7 - 2
    // 25
}