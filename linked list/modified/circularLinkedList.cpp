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

//inserts node at start of LL, head part
void insertAtHead(node *&head, int value)
{
    node *n = new node(value);
    if (head == NULL)
    {
        //if no node, new node itself is head & tail
        n->next = n;
        //reassign head
        head = n;
        return;
    }
    node *temp = head;
    // traverse till next is head (circular)
    while (temp->next != head)
    {
        temp = temp->next;
    }
    // end now points to new node
    temp->next = n;
    //  new node's next points to head
    n->next = head;
    head = n; //head is now n, new node
}

//inserts node at end of LL, tail part
void insertAtTail(node *&head, int value)
{
    if (head == NULL)
    {
        insertAtHead(head, value);
        return;
    }
    node *n = new node(value);
    node *temp = head;
    // traverse till next is head (circular)
    while (temp->next != head)
    {
        temp = temp->next;
    }
    //attach temp's next to new node, new node's next to head, making circular
    temp->next = n;
    n->next = head;
}

void deleteAtHead(node *&head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *toDelete = head;
    //node before head, points to head's next
    temp->next = head->next;
    // head is head's next now
    head = head->next;
    delete toDelete;
}

void deletion(node *&head, int position)
{
    if (position == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;
    //traverse till position
    while (count != position - 1)
    {
        temp = temp->next;
        count++;
    }

    node *toDelete = temp->next;
    // no edge case, as circular
    temp->next = temp->next->next;

    delete toDelete;
}

void display(node *head)
{
    node *temp = head;
    do
    {
        cout << temp->data << "->";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    // 1->2->3->4->
    insertAtHead(head, 7);
    display(head);
    // 7->1->2->3->4->
    deletion(head, 3);
    display(head);
    // 7->1->3->4->
    deleteAtHead(head);
    display(head);
    // 1->3->4->
}