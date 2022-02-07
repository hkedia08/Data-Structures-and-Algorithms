// https://leetcode.com/problems/reverse-linked-list/

// Iterative approach
// Using three pointers
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
};
// recursive
class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        if (head->next == NULL)
        {
            return head;
        }
        ListNode *temp = reverse(head->next);
        // this will do operation when loop is returning
        head->next->next = head;
        head->next = NULL;
        // this was just to return head which is last node
        return temp;
    }
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;
        return reverse(head);
    }
};