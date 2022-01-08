//https://leetcode.com/problems/palindrome-linked-list/

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
        {
            fast = fast->next->next;
            slow = slow = slow->next;
        }
        return slow;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *forward = NULL;
        while (curr != NULL)
        {
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool isPalindrome(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return true;
        ListNode *mid = middleNode(head);
        ListNode *nh = mid->next;
        mid->next = NULL;
        nh = reverseList(nh);
        bool result = true;
        ListNode *c1 = head;
        ListNode *c2 = nh;
        while (c1 != NULL && c2 != NULL)
        {
            if (c1->val != c2->val)
            {
                result = false;
                break;
            }
            else
            {
                c1 = c1->next;
                c2 = c2->next;
            }
        }
        nh = reverseList(nh);
        mid->next = nh;
        return result;
    }
};