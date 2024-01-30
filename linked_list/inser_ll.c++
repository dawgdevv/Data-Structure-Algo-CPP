#include <bits/stdc++.h>
#include <vector>
using namespace std;
class node
{
public:
    int data;
    node *next;

public:
    node(int data1, node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};
node *convertarr2ll(vector<int> &arr)
{
    node *head = new node(arr[0]);
    node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        node *temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void traversal(node *temp)
{
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int check_data(node *temp, int value)
{
    while (temp != NULL)
    {

        if (temp->data == value)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}
int len(node *temp)
{
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node *insert_athead(node *head, int value)
{
    node *temp = new node(value, head);

    return temp;
}
node *insert_atlast(node *head, int value)
{
    if (head == NULL)
    {
        return new node(value);
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *newnode = new node(value);
    temp->next = newnode;

    return head;
}
node *insertat_position(node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            return new node(val);
        }
        else
            return NULL;
    }
    if (k == 1)
    {
        node *temp = new node(val, head);
        return temp;
    }
    int cnt = 0;
    node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == (k - 1))
        {
            node *x = new node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
node *insertat_value(node *head, int val, int element)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == element)
    {
        return new node(val, head);
    }

    node *temp = head;
    while (temp->next != NULL)
    {

        if (temp->next->data == element)
        {
            node *x = new node(val, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}
int main()
{
    vector<int> arr = {0, 1, 2, 3, 5};
    node *head = convertarr2ll(arr);
    // cout << head->data;

    traversal(head);
    head = insertat_value(head, 2, 1);
    traversal(head);
}