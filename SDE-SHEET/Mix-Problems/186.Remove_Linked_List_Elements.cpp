// https://leetcode.com/problems/remove-linked-list-elements/

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;
        ListNode *temp = head;
        while (temp != NULL && temp->val == val)
        {
            temp = temp->next;
        }
        head = temp;
        while (temp != NULL && temp->next != NULL)
        {
            if (temp->next->val == val)
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

// recursion
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        if (head == NULL)
            return NULL;
        head->next = removeElements(head->next, val);
        if (head->val == val)
        {
            ListNode *temp = head->next;
            delete head;
            return temp;
        }
        else
        {
            return head;
        }
    }
};