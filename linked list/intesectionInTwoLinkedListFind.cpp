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

int length(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

// makes intersection in 2 lists at given position
void makeIntersection(node *&head1, node *&head2, int position)
{
    node *temp1 = head1;
    position--;
    // traverse longer list till position
    while (position--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    // traverse till end of list 2, shorter one
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    // append temp1 to temp2's next
    temp2->next = temp1;
}

int intersectionPoint(node *head1, node *head2)
{
    int len1 = length(head1);
    int len2 = length(head2);

    int difference = 0;
    node *pointer1;
    node *pointer2;

    // assign difference, pointer one two longer list's length
    if (len1 > len2)
    {
        difference = len1 - len2;
        pointer1 = head1;
        pointer2 = head2;
    }
    else
    {
        difference = len2 - len1;
        pointer1 = head2;
        pointer2 = head1;
    }
    // traverse the longer list's pointer to 'difference' amount of nodes
    while (difference)
    {
        pointer1 = pointer1->next;
        // reached end, no intersection, return -1
        if (pointer1 == NULL)
        {
            return -1;
        }
        difference--;
    }
    // traverse both till they are equal, it is intersection point, return
    while (pointer1 != NULL && pointer2 != NULL)
    {
        if (pointer1 == pointer2)
        {
            return pointer1->data;
        }
        pointer2 = pointer2->next;
        pointer1 = pointer1->next;
    }
    // not found anything equal, return -1
    return -1;
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
    node *head2 = NULL;
    insertAtTail(head2, 8);
    insertAtTail(head2, 9);

    // cout << length(head) << endl;
    // cout << length(head2) << endl;

    makeIntersection(head, head2, 3);
    display(head);
    // 1->2->3->4->5->6->NULL
    display(head2);
    // 8->9->3->4->5->6->NULL
    cout << intersectionPoint(head, head2) << endl;
    // 3
}