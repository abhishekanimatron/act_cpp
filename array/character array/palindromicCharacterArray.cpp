// input
// 5 arora
// output
// it is palindrome.

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // extra space for null character
    char a[n + 1];
    cin >> a;

    bool isPalindrome = true;

    for (int i = 0; i < n; i++)
    {
        // if left not equal to end one/last
        if (a[i] != a[n - 1 - i])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "it is palindrome.";
    else
        cout << "not it";
}