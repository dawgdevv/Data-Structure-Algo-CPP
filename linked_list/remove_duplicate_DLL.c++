/*
The function takes a pointer to the head of the doubly linked list as an argument.

It initializes a temporary pointer temp to the head of the list.

The outer while loop iterates over the list until it reaches the end. For each node, it checks if the next node is a duplicate.

If the next node (nextnode) is a duplicate (i.e., its data is the same as the current node's data), the inner while loop is entered.

The inner while loop continues to iterate as long as it keeps finding duplicates. For each duplicate, it frees the memory allocated to the duplicate node and moves the nextnode pointer to the next node.

Once all duplicates of the current node have been removed, the next pointer of the current node is updated to point to the nextnode (which is either a node with different data or NULL if there are no more nodes).

If nextnode is not NULL, its prev pointer is updated to point back to the current node.

The temp pointer is then moved to the next node, and the process repeats until all nodes have been checked.

Finally, the function returns the head of the modified list, which no longer contains any duplicates.
*/
#include <iostream>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
    node(int data1, node *next1, node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};
node *convert_dll(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
node *removeduplicates(node *head)
{
    node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        node *nextnode = temp->next;
        while (nextnode != NULL && nextnode->data == temp->data)
        {
            node *duplicate = nextnode;
            nextnode = nextnode->next;
            free(duplicate);
        }
        temp->next = nextnode;
        if (nextnode != NULL)
        {
            nextnode->prev = temp;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> arr = {12, 3, 3, 6, 7};
    node *head = convert_dll(arr);
    print(head);
    head = removeduplicates(head);
    print(head);
}