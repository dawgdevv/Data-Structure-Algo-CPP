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
int main()
{
    vector<int> arr = {0, 1, 2, 3, 5};
    node *head = convertarr2ll(arr);
    // cout << head->data;
    node *temp = head;
    traversal(temp);
    cout << len(temp) << endl;
    cout << check_data(temp, 3) << endl;
}