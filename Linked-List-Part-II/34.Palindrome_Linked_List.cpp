// https://leetcode.com/problems/palindrome-linked-list/

// reverse half part and then check for palindrome
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;
        ListNode *prev, *curr, *next1;
        prev = NULL;
        curr = head;
        next1 = head->next;
        while (curr != NULL)
        {
            curr->next = prev;
            prev = curr;
            curr = next1;
            if (next1 != NULL)
                next1 = next1->next;
        }
        head = prev;
        return head;
    }
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast != NULL)
                fast = fast->next;
        }
        slow = reverseList(slow);
        fast = head;
        while (slow != NULL)
        {
            if ((slow->val) != (fast->val))
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};