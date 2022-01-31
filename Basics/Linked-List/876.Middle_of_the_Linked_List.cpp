//https://leetcode.com/problems/middle-of-the-linked-list/

// in case of linked list problems always check some edge cases
// 0,1,2,even, odd length of list

// most optimal solution using fast and slow pointer
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
        while (fast != NULL && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow = slow->next;
        }
        return slow;
    }
};
