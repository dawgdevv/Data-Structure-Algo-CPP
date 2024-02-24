/*The function delete_dll takes two arguments: a pointer to the head of the list (head) and the key of the node to be deleted (key).

It initializes a temporary pointer temp to head.

It enters a while loop that continues until temp becomes NULL, which is the end of the linked list.

Inside the loop, it checks if the data of the current node (temp) is equal to key.

If the data is equal to key, it means this is the node to be deleted. The steps to delete the node would be:

If temp is not the head of the list (i.e., temp->prev is not NULL), update the next pointer of the previous node to skip temp and point to temp->next.
If temp is not the last node in the list (i.e., temp->next is not NULL), update the prev pointer of the next node to skip temp and point to temp->prev.
If temp is the head of the list, update head to be the next node (temp->next).
Delete temp.
If the data is not equal to key, move temp one step forward by setting temp to temp->next.

Once the loop finishes, return the (possibly updated) head of the list.*/

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