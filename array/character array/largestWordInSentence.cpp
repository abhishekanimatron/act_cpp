// suppose we work out this  way ....and run the terminal ....we will put 1st word ...
// and to put second word we have will press  enter/space key right but our maasum sa
// compiler will think the second word is space/enter ...got it?? since it is part of
// character domain....so to ignore the enter key or  space  key that  ignore function is   used.
// so whenever  there is a cin function before cin>>char we have to put ignore()  in between
// in this video there was a cin integer before cin character so  compiler  used to assume
// that  the character is space/enter which we used to put after inputting the integer
// upvote if got it..

// input
// 10
// do or die

// output
// 3
// die

#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    cin.ignore();

    char a[n + 1];
    // to get a line as input
    cin.getline(a, n);
    cin.ignore();

    int i = 0;
    int currentLength = 0, maximumLength = 0;
    int st = 0, maxst = 0;
    while (true)
    {
        if (a[i] == ' ' || a[i] == '\0')
        { //if character encountered is space or is end of line, it means that word is over,
            // we recalculate the maximum now
            if (currentLength > maximumLength)
            {
                maximumLength = currentLength;
                maxst = st;
            }
            // as a new word has started we reset this
            currentLength = 0;
            st = i + 1;
        }
        else
        {
            // else just increase the length
            currentLength++;
        }
        if (a[i] == '\0')
            break;
        i++;
    }
    cout << maximumLength << endl;
    for (int i = 0; i < maximumLength; i++)
    {
        cout << a[i + maxst];
    }
}