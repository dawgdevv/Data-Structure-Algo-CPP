/*Create three dummy nodes: zeroHead, oneHead, and twoHead. These nodes act as the heads of three linked lists: one for nodes with data 0, one for nodes with data 1, and one for nodes with data 2.
Traverse the original linked list. For each node:

If the node's data is 0, append it to the end of the 0s list.
If the node's data is 1, append it to the end of the 1s list.
If the node's data is 2, append it to the end of the 2s list.

After the original list is completely traversed, concatenate the 0s, 1s, and 2s lists together.

Return the head of the concatenated list.*/

#include <iostream>
class Node
{
public:
    int data;
    Node *next;

    Node() : data(0), next(nullptr) {}
    Node(int data) : data(data), next(nullptr) {}
    Node(int data, Node *next) : data(data), next(next) {}
};

Node *sortList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);

    Node *zero = zeroHead;
    Node *one = oneHead;
    Node *two = twoHead;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = temp;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = temp;
        }
        else
        {
            two->next = temp;
            two = temp;
        }
        temp = temp->next;
    }

    zero->next = (oneHead->next) ? oneHead->next : twoHead->next;
    one->next = twoHead->next;
    two->next = nullptr;

    Node *newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return newHead;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create a linked list: 1 -> 2 -> 0 -> 1 -> 2
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);

    std::cout << "Original List: ";
    printList(head);

    // Sort the list
    head = sortList(head);

    std::cout << "Sorted List: ";
    printList(head);

    // Clean up memory
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
