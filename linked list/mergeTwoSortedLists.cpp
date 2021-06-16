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

//merges two lists and returns merged one's head
node *merge(node *&head1, node *&head2)
{
    node *pointer1 = head1;
    node *pointer2 = head2;
    node *dummy = new node(-1); //node pointing to merged list's head
    node *pointer3 = dummy;

    while (pointer1 != NULL && pointer2 != NULL)
    {
        //attach merged list's pointer to one with lesser data
        if (pointer1->data < pointer2->data)
        {
            pointer3->next = pointer1;
            pointer1 = pointer1->next;
        }
        else
        {
            pointer3->next = pointer2;
            pointer2 = pointer2->next;
        }
        pointer3 = pointer3->next;
    }
    //if values remain in any list attach them directly
    while (pointer1 != NULL)
    {
        pointer3->next = pointer1;
        pointer1 = pointer1->next;
        pointer3 = pointer3->next;
    }
    while (pointer2 != NULL)
    {
        pointer3->next = pointer2;
        pointer2 = pointer2->next;
        pointer3 = pointer3->next;
    }
    return dummy->next;
}

node *mergeRecursive(node *&head1, node *&head2)
{
    //base case
    if (head1 == NULL)
    {
        return head2;
    }
    //base case
    if (head2 == NULL)
    {
        return head1;
    }
    //this node stores lesser of two nodes in lists
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        // call for selected node's next, and store in result's next
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        // call for selected node's next, and store in result's next
        result->next = mergeRecursive(head1, head2->next);
    }
    //merged list
    return result;
}

int main()
{
    node *head1 = NULL;
    insertAtTail(head1, 1);
    insertAtTail(head1, 4);
    insertAtTail(head1, 5);
    insertAtTail(head1, 7);

    node *head2 = NULL;
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 6);

    display(head1);
    // 1->4->5->7->NULL
    display(head2);
    // 2->3->6->NULL
    // node *newHead = merge(head1, head2);
    // 1->2->3->4->5->6->7->NULL
    node *newHead = mergeRecursive(head1, head2);
    display(newHead);
    // 1->2->3->4->5->6->7->NULL
}