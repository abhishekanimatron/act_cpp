#include <iostream>
#include <stack>
using namespace std;

class queue
{
    stack<int> s1;
    stack<int> s2;

public:
    // push elements on stack one
    void push(int x)
    {
        s1.push(x);
    }
    // pops and returns the popped element
    int pop()
    {
        // if both stack is empty
        if (s1.empty() && s2.empty())
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        // if stack two is empty
        if (s2.empty())
        {
            // push stack one's elements to stack two, till stack one is empty
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int tope = s2.top();
        s2.pop();
        return tope;
    }
    bool empty()
    {
        if (s1.empty() && s2.empty())
            return true;
        return false;
    }
};

int main()
{
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;
    // 1
    // 2
    // 3
    // 4
    // Queue is empty.
    // -1
    // 1
}