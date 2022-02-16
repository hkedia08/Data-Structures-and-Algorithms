// https://leetcode.com/problems/linked-list-cycle-ii/

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL)
            return NULL;
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        do
        {
            if (slow == NULL)
                return NULL;
            slow = slow->next;
            if (fast == NULL)
                return NULL;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        } while (slow != fast);
        if (slow == NULL || fast == NULL)
        {
            return NULL;
        }
        fast = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

// another approach was to use map and store nodes if same node occur that means it is cycle and startng point