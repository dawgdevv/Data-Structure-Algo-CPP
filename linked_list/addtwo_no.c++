/*The function findMiddleNode takes a pointer to the head of the linked list as its argument.

It checks if the head is nullptr. If it is, the list is empty, and the function returns nullptr.

It initializes two pointers: slowPtr and fastPtr, both set to head.

It enters a while loop that continues until fastPtr becomes nullptr or fastPtr->next becomes nullptr, which is the end of the linked list.

Inside the loop:

It moves slowPtr one step forward by setting slowPtr to slowPtr->next.
It moves fastPtr two steps forward by setting fastPtr to fastPtr->next->next.
Once the loop finishes (when fastPtr is nullptr or fastPtr->next is nullptr), slowPtr will be at the middle of the list, which is returned by the function.*/
#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;
    int carry = 0;

    while (l1 || l2 || carry)
    {
        int sum = carry;
        if (l1)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        curr->next = new ListNode(sum % 10);
        curr = curr->next;
    }

    return dummy->next;
}

int main()
{
    // Create two linked lists
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Add the two numbers
    ListNode *result = addTwoNumbers(l1, l2);

    // Print the result
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}