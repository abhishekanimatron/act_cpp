#include <iostream>
using namespace std;

#define n 100

class CustomStack
{
    int *a;
    int top;

public:
    CustomStack()
    {
        a = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "Stack full" << endl;
            return;
        }
        top++;
        a[top] = x;
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty, no element to pop." << endl;
            return;
        }
        top--;
    }
    int tope()
    {
        if (top == -1)
        {
            cout << "Stack is empty, no element to pop." << endl;
            return -1;
        }
        return a[top];
    }
    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    CustomStack stac;
    stac.push(1);
    stac.push(2);
    stac.push(3);

    cout << stac.tope() << endl; //4
    stac.pop();
    cout << stac.tope() << endl; //3
    stac.pop();
    stac.pop();
    stac.pop();
    cout << "empty? " << stac.empty() << endl;
    // 4
    // 3
    // 2
    // 1
    // Stack is empty, no element to pop.
    // -1
    // Stack is empty, no element to pop.
    // 0
}