// We have to paint n boards of length {A1, A2…An}. There are k painters available and each takes 1 unit time to paint 1 unit of board. The problem is to find the minimum time to get
// this job done under the constraints that any painter will only paint continuous sections of boards, say board {2, 3, 4} or only board {1} or nothing but not board {2, 4, 5}.

// Input : k = 2, A = {10, 10, 10, 10}
// Output : 20.
// Here we can divide the boards into 2
// equal sized partitions, so each painter
// gets 20 units of board and the total
// time taken is 20.

// Input : k = 2, A = {10, 20, 30, 40}
// Output : 60.
// Here we can divide first 3 boards for
// one painter and the last board for
// second painter.

// Possible divisions are:

// * One partition: so time is 100.

// * Two partitions: (10) & (20, 30, 40), so time is 90. Similarly we can put the first divider
// after 20 (=> time 70) or 30 (=> time 60); so this means the minimum time: (100, 90, 70, 60) is 60.
#include <iostream>
using namespace std;

// returns minimum number of painters required to paint "limit" number of boards
int feasible(int boards[], int numberOfBoards, int limit)
{
    int sum = 0, painters = 1;
    for (int i = 0; i < numberOfBoards; i++)
    {
        sum += boards[i];
        if (sum > limit)
        { // for next count
            sum = boards[i];
            painters++;
        }
    }
    return painters;
}
// returns the minimum time required to paint the boards given by number of painters
int paintingTime(int boards[], int numberOfBoards, int numberOfPainters)
{
    // total length of boards to paint
    int totalLengthOfBoards = 0;
    int maximumBoardLength = 0; //length/size of maximum board
    // calculate these values
    for (int i = 0; i < numberOfBoards; i++)
    {
        maximumBoardLength = max(maximumBoardLength, boards[i]);
        totalLengthOfBoards += boards[i];
    }
    // since 1 unit length of board requires 1 unit of time to paint the lower time limit required will be maximum board's length
    int lowerLimit = maximumBoardLength;
    int higherLimit = totalLengthOfBoards; //and higher limit will be total length of boards
    // for all middle values
    while (lowerLimit < higherLimit)
    {
        int middle = (lowerLimit + higherLimit) / 2;
        // number of painters to paint middle (no. of boards)
        int painters = feasible(boards, numberOfBoards, middle);
        // if number painter required to paint that many boards is less than given painters
        // search for better answer (lower value) in left part of array, that is lower values, to find minimal time
        if (painters <= numberOfPainters)
            higherLimit = middle;
        else
            // else search in right half of array
            lowerLimit = middle + 1;
    }
    return lowerLimit;
}

int main()
{
    int a[] = {10, 20, 30, 40};
    int size = 4;
    int painters = 2;
    cout << "Time: " << paintingTime(a, size, painters) << "\n";
}