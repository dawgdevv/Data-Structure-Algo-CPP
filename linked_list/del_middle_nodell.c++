// algo to delete middle node of linked list
// time complexity O(n)
/*
Tortoise and Hare algorithm (Floyd's Cycle Detection Algorithm):
This algorithm is used to detect a cycle in a linked list but can be adapted to find the middle node.
It uses two pointers, one (the "tortoise") advances one node at a time, and the other (the "hare") advances two nodes at a time.
When the hare reaches the end of the list, the tortoise will be at the middle node.
To delete the middle node, you would need to keep track of the previous node while advancing the tortoise.
*/
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
    Node(int x, Node *n)
    {
        data = x;
        next = n;
    }
};
// By using Floyd's Cycle Detection Algorithm
Node *delnode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *middle = slow->next;
    slow->next = slow->next->next;
    free(middle);
    return head;
}
// BY using length of linked list
Node *delnode(Node *head)
{
    Node *temp = head;
    int n = 0;
    while (temp != NULL)
    {
        n++;
        temp = temp->next;
    }
    Node *prev = head;
    for (int i = 0; i < n / 2 - 1; i++)
    {
        prev = prev->next;
    }
    Node *middle = prev->next;
    prev->next = prev->next->next;
    delete (middle);
    return head;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    head = delnode(head);
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}