#include <iostream>
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
node *pair_sum_dll(node *head, int sum)
{
}
int main()
{
}