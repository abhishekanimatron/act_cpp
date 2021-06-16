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

// this function detects and returns true if it has cycle
bool detectCycle(node *head)
{
    //two pointers, fast & slow
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next; //moves twice as fast
        slow = slow->next;

        // if they meet at certain point, there's a cycle
        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

// this function makes a cycle in given LL, at position
void makeCycle(node *&head, int position)
{
    node *temp = head;
    node *startingNode; //gives the starting point to the cycle

    int count = 1; //1-indexed
    while (temp->next != NULL)
    {
        if (count == position)
        {
            // if count reaches the desired position
            startingNode = temp;
        }
        temp = temp->next;
        count++;
    }
    // by here, we have reached ending node of original list
    // attach starting position of cycle to last node's next value, making a cycle
    temp->next = startingNode;
}

//this function removes cycle from LL
void removeCycle(node *&head)
{
    //slow, fast pointers
    node *slow = head;
    node *fast = head;

    //traversal till they are equal
    do
    {
        fast = fast->next->next;
        slow = slow->next;
    } while (slow != fast);
    //reset fast's position to head
    fast = head;
    // traverse till they meet again (at starting position of cycle)
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // replace slow's next, which was going through the cycle, to NULL, breaking the cycle
    slow->next = NULL;
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
    // cout << detectCycle(head) << endl;
    // //output: 0
    makeCycle(head, 3);
    cout << detectCycle(head) << endl;
    //output: 1
    removeCycle(head);
    cout << detectCycle(head) << endl;
    //output: 0
    display(head);
    // output: 1->2->3->4->5->6->NULL
}