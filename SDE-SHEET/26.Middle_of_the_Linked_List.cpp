// https://leetcode.com/problems/middle-of-the-linked-list/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != NULL)
                fast = fast->next;
        }
        return slow;
    }
};