
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
int len(node *head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
node *deletehead(node *head) /// delete the linked list head element////
{
    if (head == NULL)
        return head;
    node *temp = head;
    head = head->next;
    free(temp);
    return head;
}
node *delete_atlast(node *head) /// delete the linked list last element////
{
    node *temp = NULL;
    node *current = head;
    if (head == NULL || head->next == NULL)
        return NULL;
    while (current->next->next != NULL)
    {
        temp = current;
        current = current->next;
    }
    temp->next = NULL;
    free(current);
    return head;
}
node *delete_atindex(node *head, int index) /// delete the linked list at a given index element////
{

    if (head == NULL)
        return head;
    if (index == 1)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    node *current = head;
    node *prev = NULL;
    while (current != NULL)
    {
        count++;
        if (count == index)
        {
            prev->next = prev->next->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    return head;
}
node *delete_atvalue(node *head, int elm) /// delete the linked list at a given index element////
{

    if (head == NULL)
        return head;
    if (head->data == elm)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node *current = head;
    node *prev = NULL;
    while (current != NULL)
    {

        if (current->data == elm)
        {
            prev->next = prev->next->next;
            free(current);
            break;
        }
        prev = current;
        current = current->next;
    }

    return head;
}
int main()
{
    vector<int> arr = {0, 1, 2, 3, 5};
    node *head = convertarr2ll(arr);
    // cout << head->data;
    node *temp = head;
    traversal(temp);
    head = delete_atvalue(head, 3);
    traversal(head);

    // cout << len(head) << endl;
    // cout << check_data(head, 3) << endl;
}