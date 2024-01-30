#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {

        this->data = data;
        next = NULL;
    }
};
Node *oddEvenList(Node *head)
{
    // Write your code here.
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *odd = head;
    Node *even = head->next;
    Node *evenhead = head->next;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenhead;           
    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Example usage

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    // Calling the oddEvenList function
    head = oddEvenList(head);

    cout << "List after rearranging odd and even nodes: ";
    printList(head);

    return 0;
}
