// https://leetcode.com/problems/rotate-list/

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0)
            return head;
        ListNode *temp = head;
        int len = 1;
        while (temp->next != NULL)
        {
            len++;
            temp = temp->next;
        }
        temp->next = head;
        k = k % len;
        // this is mistake i was doing
        k = len - k;
        while (k > 0)
        {
            temp = temp->next;
            k--;
        }
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};