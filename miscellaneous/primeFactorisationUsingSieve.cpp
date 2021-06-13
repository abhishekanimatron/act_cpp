#include <iostream>
using namespace std;

void primeFactors(int n)
{
    int smallPrimeFactors[100] = {0};
    // we set a numbers array with zeroes
    //for each number we assign its own value as its prime factor
    for (int i = 2; i <= n; i++)
    {
        smallPrimeFactors[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        //if number is same as we assigned before
        if (smallPrimeFactors[i] == i)
        {
            // sieve
            for (int j = i * i; j <= n; j += i)
            {
                // we mark this only if it's unmarked,
                //if its marked then this is not its shortest prime factor, i.e. its already marked before
                if (smallPrimeFactors[j] == j)
                {
                    // otherwise the current variable i is an shortest prime factor
                    smallPrimeFactors[j] = i;
                }
            }
        }
    }
    // to print its prime factors
    while (n != 1)
    {
        cout << smallPrimeFactors[n] << " ";
        n = n / smallPrimeFactors[n];
    }
}

int main()
{
    int n;
    cin >> n;
    primeFactors(n);

    //input: 42
    //output: 2 3 7
}