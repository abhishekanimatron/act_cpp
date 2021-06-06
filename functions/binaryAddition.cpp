#include <iostream>
using namespace std;

int reverse(int n)
{
    int ans = 0;
    while (n > 0)
    {
        int last = n % 10;
        ans = ans * 10 + last;
        n /= 10;
    }
    return ans;
}

int addBin(int a, int b)
{
    int ans = 0;
    int carry = 0;

    while (a > 0 && b > 0)
    {
        //0,0
        if (a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + carry;
            carry = 0;
        }
        //1,0  or 0,1
        else if ((a % 2 == 0 && b % 2 == 1) || (a % 2 == 1 && b % 2 == 0))
        {
            if (carry == 1)
            {
                ans = ans * 10 + 0;
                carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                carry = 0;
            }
        }
        else
        // 1,1
        {
            ans = ans * 10 + carry;
            carry = 1;
        }
        a /= 10;
        b /= 10;
    }
    // when one number remains ...a
    while (a > 0)
    {
        if (carry == 1)
        {
            if (a % 2)
            {
                ans = ans * 10 + 0;
                carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                carry = 0;
            }
        }
        else
            ans = ans * 10 + (a % 2);
        a /= 10;
    }
    while (b > 0)
    {
        if (carry == 1)
        {
            if (b % 2)
            {
                ans = ans * 10 + 0;
                carry = 1;
            }
            else
            {
                ans = ans * 10 + 1;
                carry = 0;
            }
        }
        else
            ans = ans * 10 + (b % 2);
        b /= 10;
    }
    // if extra carry but no number remain ahead
    if (carry == 1)
    {
        ans = ans * 10 + 1;
    }
    ans = reverse(ans);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << addBin(a, b) << endl;
}