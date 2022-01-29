//https://leetcode.com/problems/delete-node-in-a-linked-list/

// The problem is very misleading but the logic is that we just put the address of delete node->next and delete that node

class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        if (node->next == NULL)
        {
            delete node;
            return;
        }
        swap(node->val, node->next->val);
        ListNode *temp = node->next;
        node->next = node->next->next;
        // always delete the node otherwise it will create memory leak
        delete temp;
    }
};