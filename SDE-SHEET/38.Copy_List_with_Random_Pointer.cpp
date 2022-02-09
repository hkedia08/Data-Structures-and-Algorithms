// https://leetcode.com/problems/copy-list-with-random-pointer/

// using map
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node *, Node *> m;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copy = new Node(temp->val);
            m[temp] = copy;
            temp = temp->next;
        }
        temp = head;
        while (temp != NULL)
        {
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }
};
//  O(1) space
class Solution
{
public:
    void CopyList(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *copy = new Node(temp->val);
            Node *n = temp->next;
            temp->next = copy;
            copy->next = n;
            temp = n;
        }
    }
    void Randompointer(Node *head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->random != NULL)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
    }
    Node *detach(Node *head)
    {
        Node *dummy = new Node(-1);
        Node *temp = head;
        Node *tail = dummy;
        while (temp != NULL)
        {
            tail->next = temp->next;
            tail = tail->next;
            temp->next = tail->next;
            temp = temp->next;
        }
        return dummy->next;
    }
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return head;
        CopyList(head);
        Randompointer(head);
        return detach(head);
    }
};