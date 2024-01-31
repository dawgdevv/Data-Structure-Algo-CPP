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