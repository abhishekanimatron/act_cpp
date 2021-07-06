#include <iostream>
#include <algorithm>
using namespace std;

// returns true if there exists a set of k elements, which have distance of >=middle between them
bool feasible(int middle, int a[], int size, int k)
{
    int position = a[0];
    int elements = 1;
    for (int i = 0; i < size; i++)
    {
        // if the distance between the current element and element at position is >=middle
        if (a[i] - position >= middle)
        {
            // change position to current element
            position = a[i];
            // increment element
            elements++;
            // and if the number of elements becomes equal to required k elements return true
            if (elements == k)
                return true;
        }
    }
    // else
    return false;
}

int maximumDistance(int a[], int size, int k)
{
    // sort array
    sort(a, a + size);
    int answer = -1;
    // left and right indexes
    int left = a[0];
    int right = a[size - 1];

    while (left < right)
    {
        // take out middle number of those two
        int middle = (left + right) / 2;
        if (feasible(middle, a, size, k))
        {
            // if there is k elements such that this (middle) distance is between them,
            answer = max(answer, middle); //change answer to maximum of the two
            // and look for greater number than middle from right array, meaning change left to middle (i.e. look from mid to right)
            left = middle + 1;
        }
        else
            // if not feasible look in left array, meaning for smaller numbers
            right = middle;
    }
    return answer;
}

int main()
{
    int a[] = {1, 2, 9, 4, 22};
    int size = 5;
    int k = 3; //no. of elements to be searched
    cout << "Max. distance: " << maximumDistance(a, size, k) << "\n";
    // 8, taking 1, 9, 22
}