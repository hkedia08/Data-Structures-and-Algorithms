// https://leetcode.com/problems/merge-k-sorted-lists/

class cmp
{
public:
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val;
    }
};
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // min priority queue in c++ stl
        priority_queue<ListNode *, vector<ListNode *>, cmp> q;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
                q.push(lists[i]);
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (!q.empty())
        {
            ListNode *temp = q.top();
            q.pop();
            tail->next = temp;
            tail = temp;
            if (temp->next != NULL)
                q.push(temp->next);
        }
        return dummy->next;
    }
};
// Time complexity-> O(Nlog(K)) where log(k) for heap
// space -> O(Log(k))
