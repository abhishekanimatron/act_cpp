#include <iostream>
using namespace std;

//node class
class node
{
public:
    // data in the node and pointer to nextnode
    int data;
    node *next;

    // node constructor 'intialization'
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

//insert node at tail
//parameters:
//linked list's head passed as reference, a value to be inserted
void insertAtTail(node *&head, int value)
{
    // node creation via constructor
    node *n = new node(value);
    //if no node in the list insert at head, 'first value'
    if (head == NULL)
    {
        head = n;
        return;
    }
    // if we use head to traverse list, we lose head variable, so
    // we take temp
    node *temp = head;

    // as last node points to null, we traverse temp till that
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    // and assign 'n', the node we created earlier temp's next, i.e. the last node (temp)
    temp->next = n;
}

//as we have to only display we simply take head (not as a reference)
void display(node *head)
{
    node *temp = head;
    //traverse and display each node's data
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    // display NULL at end
    cout << "NULL" << endl;
}

void evenAfterOdd(node *&head)
{
    //edge case
    if (head == NULL)
        return;
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;

    while (true)
    {
        // no more elements to be added
        if (!odd || !even || !(even->next))
        {
            odd->next = evenStart;
            break;
        }
        odd->next = even->next;
        odd = even->next;
        // no more odd, make even's next NULL and attach evenStart
        if (odd->next == NULL)
        {
            even->next = NULL;
            odd->next = evenStart;
            break;
        }
        even->next = odd->next;
        even = odd->next;
    }
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
    insertAtTail(head, 7);
    display(head);
    // 1->2->3->4->5->6->NULL
    evenAfterOdd(head);
    display(head);
    // 1->3->5->2->4->6->NULL
    // 1->3->5->7->2->4->6->NULL
}