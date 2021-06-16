#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *previous;

    node(int value)
    {
        data = value;
        next = NULL;
        previous = NULL;
    }
};

void insertAtHead(node *&head, int value)
{

    node *n = new node(value);
    // new node's next will be head
    n->next = head;
    // edge case
    if (head != NULL)
        head->previous = n;
    //new head is now n
    head = n;
}

void insertAtTail(node *&head, int value)
{
    // edge case
    if (head == NULL)
    {
        insertAtHead(head, value);
        return;
    }

    node *n = new node(value);
    node *temp = head;
    // traverse till end node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // assign nodes, end node's next to 'n', n's previous to temp
    temp->next = n;
    n->previous = temp;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << endl;
}

void deleteAtHead(node *&head)
{

    node *toDelete = head;
    // head's next is now head
    head = head->next;
    // new head's previous is now NULL, removing previous head in between
    head->previous = NULL;

    delete toDelete;
}

void deletion(node *&head, int position)
{
    //edge case
    if (position == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;

    //traverse till last node or the position specified
    while (temp != NULL && count != position)
    {
        temp = temp->next;
        count++;
    }
    // temps' previous's next points to temp's next, removing temp's connection in between
    temp->previous->next = temp->next;
    if (temp->next != NULL)
    {
        // temps' next's previous points to temp's previous, removing temp's connection in between
        temp->next->previous = temp->previous;
    }
    delete temp;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);
    insertAtHead(head, 6);
    display(head);
    //output: 6->1->2->3->4->5->
    deletion(head, 3);
    display(head);
    //output: 6->1->3->4->5->
    deleteAtHead(head);
    display(head);
    //output: 1->3->4->5->
}