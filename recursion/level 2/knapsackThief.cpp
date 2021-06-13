// Given n items, each item has a certain value and weight. We have to maximize the
// value of the objects we can accommodate in a bag of weight W.
// Idea: For each item, we have two choices, either to include it or exclude it.

#include <iostream>
using namespace std;
// prices array with each item's price, weightsof each, number of items, weight limit of sack
int sack(int prices[], int weights[], int n, int W)
{
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (weights[n - 1] > W)
    {
        // if selecting the weight overloads the limit of sack
        return sack(prices, weights, n - 1, W);
    }
    //if it doesn't overload we select the maximum recursively for if we select that item or not
    // by selecting we add its price and also reducing its weight from the sack limit
    return max(sack(prices, weights, n - 1, W - weights[n - 1]) + prices[n - 1], sack(prices, weights, n - 1, W));
}
int main()
{
    int weights[] = {10, 20, 30};
    int prices[] = {100, 50, 150};
    int W = 50;
    cout << sack(prices, weights, 3, W);
    //output:250
}