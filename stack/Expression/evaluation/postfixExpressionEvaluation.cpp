#include <iostream>
#include <stack>
#include <math.h>

using namespace std;

int postfixEvaluation(string s)
{
    stack<int> stac;
    // from front
    for (int i = 0; i < s.length(); i++)
    {
        // if operand push to stack
        if (s[i] >= '0' && s[i] <= '9')
        {
            stac.push(s[i] - '0');
        }
        else
        {
            // store the operands each in 1 & 2
            // 2nd operator is in top
            int operand2 = stac.top();
            stac.pop();
            int operand1 = stac.top();
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
    cout << postfixEvaluation("46+2/5*7+") << endl;
    // output: 32
    // (((4+6)/2)*5)+7
    // ((10/2)*5)+7
    // 5*5 + 7
    // 32
}