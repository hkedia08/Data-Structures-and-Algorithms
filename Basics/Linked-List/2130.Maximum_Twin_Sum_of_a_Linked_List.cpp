//https://leetcode.com/contest/biweekly-contest-69/problems/maximum-twin-sum-of-a-linked-list/

//variation of palindrome in linked list

// O(n) approach not allowed in interviews but good during online machine round
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        vector<int> store;
        while (head != NULL)
        {
            store.push_back(head->val);
            head = head->next;
        }
        int lo = 0, hi = store.size() - 1;
        int ans = 0;
        while (lo < hi)
        {
            ans = max(ans, store[lo] + store[hi]);
            lo++;
            hi--;
        }
        return ans;
    }
};

// O(1) space

class Solution
{
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

public:
    int pairSum(ListNode *head)
    {
        if (head == NULL)
            return 0;
        int ans = 0;
        ListNode *mid = middleNode(head);
        ListNode *nh = mid->next;
        mid->next = NULL;
        nh = reverseList(nh);
        ListNode *c1 = head;
        ListNode *c2 = nh;
        while (c1 != NULL && c2 != NULL)
        {
            ans = max(ans, c1->val + c2->val);
            c1 = c1->next;
            c2 = c2->next;
        }
        nh = reverseList(nh);
        mid->next = nh;
        return ans;
    }
};
