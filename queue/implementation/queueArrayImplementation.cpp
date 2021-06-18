#include <iostream>
using namespace std;

#define n 20

class queue
{
    int *a;
    int front;
    int back;

public:
    queue()
    {
        a = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue is full." << endl;
            return;
        }
        // increase back and add its value
        back++;
        a[back] = x;
        //if first value is inserted, front is incremented to 0
        if (front == -1)
            front++;
    }
    void pop()
    {
        // if no value, front is -1, or greater than back
        if (front == -1 || front > back)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        //increase front, leaving old value behind (left)
        front++;
    }
    // returns value at front (leftmost)
    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return a[front];
    }
    bool empty()
    {
        if (front == -1 || front > back)
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
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;
    //output:
    // 1
    // 2
    // 3
    // 4
    // 1
}