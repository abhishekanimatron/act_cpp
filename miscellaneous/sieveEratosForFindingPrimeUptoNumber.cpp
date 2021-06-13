#include <iostream>
using namespace std;

void primeSieve(int n)
{
    //intialize a primes array with zeroes to store numbers
    int primes[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        // if the number is not marked 1
        if (primes[i] == 0)
        {
            // start from square of i till n
            for (int j = i * i; j <= n; j += i)
            {
                //and mark the its (i's) multiples as 1, i.e. they're not prime
                primes[j] = 1;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        // if the number is 0, that is not marked implying that it is prime
        if (primes[i] == 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    primeSieve(n);

    //input: 30
    //output: 2 3 5 7 11 13 17 19 23 29
}