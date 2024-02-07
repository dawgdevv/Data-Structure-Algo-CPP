#include <iostream>

class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
node *delete_dll(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            if (temp == head)
            {
                head = head->next;
            }
            node *nextnode = temp->next;
            node *prevnode = temp->prev;
            if (nextnode)
            {
                nextnode->prev = prevnode;
            }
            if (prevnode)
            {
                prevnode->next = nextnode;
            }
            delete (temp);
            temp = nextnode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    // Create a doubly linked list
    node *head = new node(1);
    node *second = new node(2);
    node *third = new node(3);
    node *fourth = new node(2);
    node *fifth = new node(5);

    // Connect the nodes
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;
    third->next = fourth;
    fourth->prev = third;
    fourth->next = fifth;
    fifth->prev = fourth;

    // Print the original list
    node *temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << "\n";
    // Delete nodes with key = 2
    head = delete_dll(head, 2);

    // Print the modified list
    temp = head;
    while (temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}