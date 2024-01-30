#include <bits/stdc++.h>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *prev;

public:
    node(int data1, node *next1, node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }

public:
    node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
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
        cout << temp->data << endl;
        temp = temp->next;
    }
}

node *insert_athead(node *head, int val)
{
    node *newhead = new node(val, head, nullptr);
    head->prev = newhead;
    return newhead;
}
node *insert_attail(node *head, int value)
{
    node *crnt = head;

    while (crnt->next != NULL)
    {
        crnt = crnt->next;
    }
    node *back = crnt->prev;
    node *newval = new node(value, crnt, back);

    back->next = newval;
    crnt->prev = newval;
    return head;
}
node *insert_atindex(node *head, int index, int value)
{
    if (index == 1)
    {
        return insert_athead(head, value);
    }
    node *current = head;
    int count = 0;
    while (current != NULL)
    {
        count++;
        if (count == index)
            break;
        current = current->next;
    }
    node *back = current->prev;
    node *newnode = new node(value, current, back);
    back->next = newnode;
    current->prev = newnode;
    return head;
}
void insertatnode(node *gnode, int value)
{
    node *back = gnode->prev;
    node *newnode = new node(value, gnode, back);
    back->next = newnode;
    gnode->prev = newnode;
}
int main()
{
    vector<int> arr = {12, 3, 5, 6, 7};
    node *head = convert_dll(arr);
    print(head);
    // head = insert_athead(head, 10);
    // head = insert_athead(head, 20);
    // head = insert_athead(head, 30);
    insertatnode(head->next, 2);
    print(head);
    return 0;
}