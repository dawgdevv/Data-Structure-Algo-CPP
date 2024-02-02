#include <iostream>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
int findlen(Node *slow, Node *fast)
{
    int len = 1;
    slow = slow->next;
    while (slow != fast)
    {
        slow = slow->next;
        len++;
    }
    return len;
}
int detectCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return findlen(slow, fast);
        }
    }
    return 0;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = second; // cycle...

    int len = detectCycle(head);
    cout << len << endl;
}