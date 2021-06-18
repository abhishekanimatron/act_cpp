#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

class queue
{
    node *front;
    node *back;

public:
    queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        node *n = new node(x);
        //first node inserted
        if (front == NULL)
        {
            front = n;
            back = n;
            return;
        }
        //back's next is now n
        back->next = n;
        // new n (node) is now back
        back = n;
    }
    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        node *toDelete = front;
        //move front one step ahead
        front = front->next;
        delete toDelete;
    }
    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }
    bool empty()
    {
        if (front == NULL)
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