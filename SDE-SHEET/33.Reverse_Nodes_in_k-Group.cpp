// https://leetcode.com/problems/reverse-nodes-in-k-group/

// recursive approach
// Time - O(N) and space O(N/k)
class Solution
{
public:
    void reverse(ListNode *s, ListNode *e)
    {
        ListNode *p = NULL, *c = s, *n = s->next;
        // bcz current will not be always null here
        while (p != e)
        {
            c->next = p;
            p = c;
            c = n;
            if (n != NULL)
                n = n->next;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 1)
            return head;
        ListNode *s = head, *e = head;
        int inc = k - 1;
        while (inc--)
        {
            e = e->next;
            if (e == NULL)
                return head;
        }
        ListNode *nextHead = reverseKGroup(e->next, k);
        // first part we reverse and rest for recursion
        reverse(s, e);
        // after reversal the e and start will reverse
        s->next = nextHead;
        return e;
    }
};

// iterative approach
class Solution
{
public:
    void reverse(ListNode *s, ListNode *e)
    {
        ListNode *p = NULL, *c = s, *n = s->next;
        // bcz current will not be always null here
        while (p != e)
        {
            c->next = p;
            p = c;
            c = n;
            if (n != NULL)
                n = n->next;
        }
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 1)
            return head;
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *beforestart = dummy, *e = head;
        int i = 0;
        while (e != NULL)
        {
            i++;
            if (i % k == 0)
            {
                ListNode *temp = e->next, *s = beforestart->next;
                reverse(s, e);
                beforestart->next = e;
                s->next = temp;
                beforestart = s;
                e = temp;
            }
            else
            {
                e = e->next;
            }
        }
        return dummy->next;
    }
};