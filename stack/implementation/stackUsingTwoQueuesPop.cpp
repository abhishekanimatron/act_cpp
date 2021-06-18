//pop costly
#include <iostream>
#include <queue>
using namespace std;

class stacke
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    stacke()
    {
        N = 0;
    }
    void pop()
    {
        // if q1 empty, no element
        if (q1.empty())
            return;
        //else, push q1's elements to q2 until only one element is in q1
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        // pop the last remaining element
        q1.pop();
        N--;

        // swap queues
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    // push elements to q1
    void push(int x)
    {
        q1.push(x);
        N++;
    }
    int top()
    {
        // queue is empty
        if (q1.empty())
            return -1;
        return q1.back();
    }
    int size()
    {
        return N;
    }
};

int main()
{
    stacke stac;
    stac.push(1);
    stac.push(2);
    stac.push(3);
    stac.push(4);

    cout << stac.top() << endl;
    stac.pop();
    cout << stac.top() << endl;
    stac.pop();
    cout << stac.top() << endl;
    stac.pop();
    cout << stac.top() << endl;
    stac.pop();
    cout << stac.size() << endl;
    // output:
    // 4
    // 3
    // 2
    // 1
    // 0
}