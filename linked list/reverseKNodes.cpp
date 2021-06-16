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

// returns a head node which has each of k node's reversed in itself
node *reverseKNodes(node *&head, int k)
{
    node *previousPointer = NULL;
    node *currentPointer = head;
    node *nextPointer;

    // count is zero
    int count = 0;
    //till either current is null, or count increses the given k value
    while (currentPointer != NULL && count < k)
    {
        // reverse the links
        nextPointer = currentPointer->next;
        currentPointer->next = previousPointer;
        previousPointer = currentPointer;
        currentPointer = nextPointer;
        //increment counter
        count++;
    }
    // if list is not ended
    if (nextPointer != NULL)
    {
        // recursively call from next pointer, and store it in head's next
        // as it is reversed
        head->next = reverseKNodes(nextPointer, k);
    }
    return previousPointer;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    int k = 2;
    node *newHead = reverseKNodes(head, k);
    //output:
    // 1->2->3->4->NULL
    // 2->1->4->3->NULL
    display(newHead);
}