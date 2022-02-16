// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

// recursion
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newhead = deleteDuplicates(head->next);
        if (head->val == newhead->val)
            return newhead;
        else
        {
            head->next = newhead;
            return head;
        }
    }
};

// iteration
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *temp = head;
        while (temp->next != NULL)
        {
            if (temp->val == temp->next->val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};