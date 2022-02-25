// https://leetcode.com/problems/add-two-numbers/

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        ListNode *head;
        if (l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        if (l1 == NULL)
        {
            swap(l1, l2);
        }
        head = l1;
        ListNode *temp = l1;
        while (l1 != NULL && l2 != NULL)
        {
            int data = l1->val + l2->val;
            data += carry;
            l1->val = data % 10;
            carry = data / 10;
            temp = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (carry > 0 && l1 != NULL)
        {
            int data = l1->val;
            data += carry;
            l1->val = data % 10;
            carry = data / 10;
            temp = l1;
            l1 = l1->next;
        }
        if (l2 != NULL)
            temp->next = l2;
        while (carry > 0 && l2 != NULL)
        {
            int data = l2->val;
            data += carry;
            l2->val = data % 10;
            carry = data / 10;
            temp = l2;
            l2 = l2->next;
        }
        if (carry > 0)
        {
            temp->next = new ListNode(carry);
        }
        return head;
    }
};
