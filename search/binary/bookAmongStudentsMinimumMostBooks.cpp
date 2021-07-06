// Page allocation problem
// Input : pages[] = {12, 34, 67, 90}
//         m = 2
// Output : 113
// Explanation:
// There are 2 number of students. Books can be distributed
// in following fashion :
//   1) [12] and [34, 67, 90]
//       Max number of pages is allocated to student
//       2 with 34 + 67 + 90 = 191 pages
//   2) [12, 34] and [67, 90]
//       Max number of pages is allocated to student
//       2 with 67 + 90 = 157 pages
//   3) [12, 34, 67] and [90]
//       Max number of pages is allocated to student
//       1 with 12 + 34 + 67 = 113 pages

// Of the 3 cases, Option 3 has the minimum pages = 113.

// The idea is to use Binary Search. We fix a value for the number of pages as mid of current minimum and maximum. We initialize minimum and maximum as 0 and sum-of-all-pages respectively. If a current mid can be a solution, then we search on the lower half, else we search in higher half.
// Now the question arises, how to check if a mid value is feasible or not? Basically, we need to check if we can assign pages to all students in a way that the maximum number doesn’t exceed current value. To do this, we sequentially assign pages to every student while the current number of assigned pages doesn’t exceed the value. In this process, if the number of students becomes more than m, then the solution is not feasible. Else feasible.

#include <iostream>
#include <climits>
using namespace std;
// return true if students required to satisfy minimum condition (which is pages of book) is less than total students, else false
// takes array of pages in each book, no. of students, books, and minimum pages allocation for student who gets most books
bool feasible(int a[], int numberOfBooks, int numberOfStudents, int minimum)
{
    int studentsRequired = 1;
    // sum is the no. of pages a student with most books gets
    int sum = 0;
    for (int i = 0; i < numberOfBooks; i++)
    {
        // if this(current) book has more pages than value (minimum) passed return false
        if (a[i] > minimum)
            return false;
        // if total pages of books plus this book's page is greater than passed value
        if (sum + a[i] > minimum)
        {
            // increment students, and set sum to this book's pages, as he has already surpassed the minimum possible so, new student should get the books now
            studentsRequired++;
            sum = a[i];
            // and if required students exceeds no. of students, return false
            if (studentsRequired > numberOfStudents)
                return false;
        }
        // if it isn't greater than the value, just add this book's page to sum
        else
        {
            sum += a[i];
        }
    }
    return true;
}
// array of pages of books, number of books, number of students
int distributeBooks(int a[], int numberOfBooks, int numberOfStudents)
{
    if (numberOfBooks < numberOfStudents)
    {
        // if no. of books < students, return -1, that is solution doesn't exist
        return -1;
    }
    // calulate sum of pages
    int sum = 0;
    for (int i = 0; i < numberOfBooks; i++)
        sum += a[i];

    // minimum starts from 0, and maximum(end) is total pages of all books
    int start = 0, end = sum;
    // no. of maximum books that can be allocated to keep it least, (student who gets most books should be minimum)
    int answer = INT_MAX;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        if (feasible(a, numberOfBooks, numberOfStudents, middle))
        {
            // if solution is feasible update answer, and look for lesser values in left half
            answer = min(answer, middle);
            end = middle - 1;
        }
        else
            start = middle + 1;
    }
    return answer;
}
int main()
{
    int a[] = {12, 34, 67, 90};
    int size = 4;
    int numberOfStudents = 2;
    cout << distributeBooks(a, size, numberOfStudents) << "\n";
    //113 taking [12,34,67] & [90] for two students
}