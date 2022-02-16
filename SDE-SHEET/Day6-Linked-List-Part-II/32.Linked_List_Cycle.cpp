// https://leetcode.com/problems/linked-list-cycle/

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL)
            return false;
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        do
        {
            if (slow == NULL)
                return false;
            slow = slow->next;
            if (fast == NULL)
                return false;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        } while (slow != fast);
        if (slow != NULL || fast != NULL)
        {
            return true;
        }
        return false;
    }
};