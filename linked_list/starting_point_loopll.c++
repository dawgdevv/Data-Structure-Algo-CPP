/*
Here's a brief explanation of the complete algorithm:
step 1: Create two pointers, slow and fast. Both start at the head of the linked list.
step 2: Move slow one step at a time and fast two steps at a time. If there is a cycle, these two pointers will meet somewhere inside the cycle.
step 3: Once they meet, reset the slow pointer to the head of the linked list and keep the fast pointer at the meeting point. Now move both pointers one step at a time. The point where they meet again is the starting point of the cycle.
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
Node *startpoint(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head->next;
    cout << startpoint(head)->data << endl;
    return 0;
}
