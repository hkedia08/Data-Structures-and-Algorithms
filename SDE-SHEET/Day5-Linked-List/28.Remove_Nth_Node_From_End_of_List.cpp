// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

// two traversal approach

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int s = 0;
        while (temp != NULL)
        {
            s++;
            temp = temp->next;
        }
        cout << s << endl;
        int start = s - n;
        if (start == 0)
        {
            head = head->next;
        }
        temp = head;
        while (start > 0)
        {
            if (start == 1)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
            start--;
        }
        return head;
    }
};

// single traversal approach
// using slow and fast pointers
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;
        for (int i = 1; i <= n; i++)
            fast = fast->next;
        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
