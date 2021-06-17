#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> stac)
{
    while (!stac.empty())
    {
        cout << stac.top() << " ";
        stac.pop();
    }
    cout << endl;
}
void insertAtBottom(stack<int> &stac, int element)
{
    if (stac.empty())
    {
        stac.push(element);
        return;
    }
    int eletop = stac.top();
    stac.pop();
    insertAtBottom(stac, element);
    stac.push(eletop);
}

void reverse(stack<int> &stac)
{
    //base case
    if (stac.empty())
        return;

    //store element
    int element = stac.top();
    stac.pop();    //pop it
    reverse(stac); //recursive call on stack remaining
    insertAtBottom(stac, element);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    // s.push(3);
    // s.push(4);
    display(s);
    //4 3 2 1
    reverse(s);
    display(s);
    //1 2 3 4
}