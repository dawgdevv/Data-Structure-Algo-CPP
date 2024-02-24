/*The function findMiddleNode takes a pointer to the head of the linked list as its argument.

It checks if the head is nullptr. If it is, the list is empty, and the function returns nullptr.

It initializes two pointers: slowPtr and fastPtr, both set to head.

It enters a while loop that continues until fastPtr becomes nullptr or fastPtr->next becomes nullptr, which is the end of the linked list.

Inside the loop:

It moves slowPtr one step forward by setting slowPtr to slowPtr->next.
It moves fastPtr two steps forward by setting fastPtr to fastPtr->next->next.
Once the loop finishes (when fastPtr is nullptr or fastPtr->next is nullptr), slowPtr will be at the middle of the list, which is returned by the function.*/
#include <iostream>

class node
{
public: // Make the data public for this test
    int data;
    node *next;
};

node *findMiddleNode(node *head)
{
    if (head == nullptr)
        return nullptr;

    node *slowPtr = head;
    node *fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    return slowPtr;
}

int main()
{
    // Create a linked list
    node *head = new node();
    head->data = 1;
    node *second = new node();
    second->data = 2;
    node *third = new node();
    third->data = 3;
    node *fourth = new node();
    fourth->data = 4;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    // Call the function
    node *middle = findMiddleNode(head);

    // Check the result
    if (middle != nullptr)
    {
        std::cout << "The middle node is: " << middle->data << std::endl;
    }
    else
    {
        std::cout << "The list is empty." << std::endl;
    }

    // Clean up
    delete head;
    delete second;
    delete third;
    delete fourth;

    return 0;
}