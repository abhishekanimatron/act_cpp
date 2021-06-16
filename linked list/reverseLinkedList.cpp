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

// iterative reverse
node *reverse(node *&head)
{
    node *previousPointer = NULL;
    node *currentPointer = head;
    node *nextPointer;
    // do this till current reaches null (end)
    while (currentPointer != NULL)
    {

        nextPointer = currentPointer->next;
        // node previous to current,  is now pointed by current pointer
        currentPointer->next = previousPointer;
        // move forward the pointers
        previousPointer = currentPointer;
        currentPointer = nextPointer;
    }
    return previousPointer; //new head, reversed
}

//recursive reverse
node *recursiveReverse(node *&head)
{
    //base condition
    // reverse is null if no node, itself if only one node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // recursive call to next node
    node *newHead = recursiveReverse(head->next);
    // head's next node now points to head itself, link reverses
    head->next->next = head;
    // head's next is now NULL, as its now last node
    head->next = NULL;
    return newHead;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    // output: 1->2->3->4->NULL
    node *newHead = reverse(head);
    // output: 4->3->2->1->NULL
    // node *newHead = recursiveReverse(head);
    // // output: 4->3->2->1->NULL
    display(newHead);
}