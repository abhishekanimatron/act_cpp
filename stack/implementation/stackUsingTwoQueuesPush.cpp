//push costly
#include <iostream>
#include <queue>
using namespace std;

class stacke
{
    int N; //stack size
    queue<int> q1;
    queue<int> q2;

public:
    stacke()
    {
        // stack's initial size
        N = 0;
    }
    void push(int x)
    {
        q2.push(x); //push to q2
        N++;
        while (!q1.empty())
        {
            //push elements from q1 to q2
            //making the current value in front
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    void pop()
    {
        //pop from queue 1, and decrease size
        q1.pop();
        N--;
    }
    int top()
    {
        return q1.front();
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
