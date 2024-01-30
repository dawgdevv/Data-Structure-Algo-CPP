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
node *delete_head(node *head)
{
    node *temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
    return head;
}
node *delete_tail(node *head)
{
    node *crnt = head;

    while (crnt->next != NULL)
    {
        crnt = crnt->next;
    }
    node *prev = crnt->prev;
    prev->next = nullptr;
    crnt->prev = nullptr;
    free(crnt);
    return head;
}
node *delete_atindex(node *head, int index)
{
    if (head == NULL)
    {
        return NULL;
    }
    int cnt = 0;
    node *knode = head;
    while (knode != NULL)
    {
        cnt++;
        if (cnt == index)
            break;
        knode = knode->next;
    }
    node *back = knode->prev;
    node *front = knode->next;
    if (back == NULL && front == NULL)
    {
        return NULL;
    }
    else if (back == NULL)
    {
        return delete_head(head);
    }
    else if (front == NULL)
    {
        delete_tail(head);
    }
    back->next = front;
    front->prev = back;

    knode->next = nullptr;
    knode->prev = nullptr;
    free(knode);
    return head;
}
void delete_atvalue(node *temp)
{

    node *back = temp->prev;
    node *front = temp->next;

    if (front == NULL)
    {
        back->next = nullptr;
        front->prev = nullptr;
        free(temp);
        return;
    }
    back->next = front;
    front->prev = back;

    temp->next = temp->prev = nullptr;
    free(temp);
}

int main()
{
    vector<int> arr = {12, 3, 5, 6, 7};
    node *head = convert_dll(arr);
    print(head);
    delete_atvalue(head->next->next->next);
    print(head);
    return 0;
}