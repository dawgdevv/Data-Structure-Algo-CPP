
#include <iostream>
#include <bits/stdc++.h>
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

Node *reverseLinkedList(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    return prev;
}

// Helper function to print the linked list
void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    // Reversing the linked list
    head = reverseLinkedList(head);

    std::cout << "Reversed Linked List: ";
    printLinkedList(head);

    // Clean up: Freeing the allocated memory
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
