#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);

    // printing
    for (auto i : dq)
        cout << i << " ";
    // output: 4 3 1 2

    dq.pop_back();
    dq.pop_front();
    cout << endl;
    for (auto i : dq)
        cout << i << " ";
    // output: 3 1
    cout << endl;
}