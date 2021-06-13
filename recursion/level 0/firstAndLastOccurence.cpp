#include <iostream>
using namespace std;

//array, size, index, key to be searched
int firstOccurence(int a[], int n, int i, int key)
{
    if (i == n)
    {
        //key not found and reached last index
        return -1;
    }
    // key found, return index
    if (a[i] == key)
        return i;
    // recursive call on next index
    return firstOccurence(a, n, i + 1, key);
}
int lastOccurence(int a[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    int restArray = lastOccurence(a, n, i + 1, key);
    // if -1, we couldn't found the key, else return rest array
    if (restArray != -1)
        return restArray;
    if (a[i] == key)
        return i;
    return -1;
}

int main()
{
    int a[] = {1, 2, 3, 4, 2, 3, 7, 8};

    // cout << firstOccurence(a, 8, 0, 3) << endl;
    // output: 8
    cout << lastOccurence(a, 8, 0, 3) << endl;
    // output: 5
}