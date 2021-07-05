#include <iostream>
using namespace std;

int catalanCalculator(int n)
{
    if (n <= 1)
        return 1;
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += catalanCalculator(i) * catalanCalculator(n - i - 1);
    }
    return result;
}

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << catalanCalculator(i) << " ";
    }
    cout << "\n";
    // 1 1 2 5 14 42 132 429 1430 4862
}