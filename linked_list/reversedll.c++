/*Initialize three pointers: current (set to head), temp (set to nullptr), and prev (not shown in the provided code, but typically used in such algorithms).

Traverse the linked list:

For each node, first save the next node by setting temp to current->next.
Reverse the direction by setting current->next to prev (not shown in the provided code).
If the list is doubly linked, also set current->prev to temp.
Move prev and current one step forward: set prev to current and current to temp.
Once current becomes nullptr, prev will be the new head of the reversed list.*/
#include <iostream>
using namespace std;
class node
{
public: // Make the data public for this test
    int data;
    node *next;
    node *prev;

    node(int data1, node *next1 = nullptr, node *prev1 = nullptr)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

node *reverseDoublyLinkedList(node *head)
{
    node *temp = nullptr;
    node *current = head;

    // Swap next and prev for all nodes of
    // doubly linked list
    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing head, check for the cases like
    // empty list and list with only one node
    if (temp != nullptr)
        head = temp->prev;

    return head;
}

int main()
{
    node *head = nullptr;
    node *temp = nullptr;

    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;

        node *newNode = new node(data);
        if (head == nullptr)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    // Now you can call reverseDoublyLinkedList or any other function on the list
    // For example:
    head = reverseDoublyLinkedList(head);

    // Print the reversed list
    temp = head;
    cout << "Reversed list: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Don't forget to delete the nodes when you're done
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}