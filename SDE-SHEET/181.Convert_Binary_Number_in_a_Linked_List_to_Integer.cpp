// https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
// two traversal
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp->next != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        int ans = 0;
        temp = head;
        while (temp != NULL)
        {
            ans += (temp->val) * pow(2, cnt);
            cnt--;
            temp = temp->next;
        }
        return ans;
    }
};

// single traversal
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        ListNode *temp = head;
        int ans = 0;
        while (temp != NULL)
        {
            ans = ans * 2;
            ans += (temp->val);
            temp = temp->next;
        }
        return ans;
    }
};