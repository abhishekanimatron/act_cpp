
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

void insertAtTail(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// returns length for the LL
int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// appends last k nodes to start of LL
node *kNodesAppend(node *&head, int k)
{
    // pointers for new LL
    node *newHead;
    node *newTail;
    //start tail pointer from head
    node *tail = head;

    int len = length(head);
    k = k % len; //incase k > len
    int count = 1;
    while (tail->next != NULL)
    {
        //traverse till tail points to the node which is just before the 'k' nodes start, which are to be appended
        if (count == len - k)
        {
            //new tail is this one
            newTail = tail;
        }
        if (count == len - k + 1)
        {
            // the node after that is new head, as they will be appended at start of new LL
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;
    return newHead;
}

int main()
{

    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    display(head);
    // output: 1->2->3->4->5->6->NULL
    node *newHead = kNodesAppend(head, 3);
    display(newHead);
    // output :4->5->6->1->2->3->NULL
}
