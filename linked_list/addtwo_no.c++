/////// skip it for now
#include <iostream>
using namespace std;
// Define the ListNode structure
struct ListNode
{
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
