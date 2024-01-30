#include <bits/stdc++.h>
#include <iostream>

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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *newhead = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newhead;
}

bool isPalindrome(Node *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *newhead = reverse(slow->next);
    Node *first = head;
    Node *second = newhead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            reverse(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverse(newhead);
    return true;
}

// Example usage
int main()
{
    // Create a sample linked list
    Node *head = new Node(1, new Node(2, new Node(3, new Node(2, new Node(1)))));

    // Check if the linked list is a palindrome
    if (isPalindrome(head))
    {
        std::cout << "The linked list is a palindrome." << std::endl;
    }
    else
    {
        std::cout << "The linked list is not a palindrome." << std::endl;
    }

    return 0;
}
