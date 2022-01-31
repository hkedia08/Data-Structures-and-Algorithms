//https://leetcode.com/problems/intersection-of-two-linked-lists/

// another methods are use set and store the nodes of list one in that and traverse the second and check if any element exist in set
// another method is to calculate both length and move the more length one to diff of more-less and move parallely

// hint ->l1+l2==l2+l1
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL)
            return NULL;
        ListNode *ptr1 = headA;
        ListNode *ptr2 = headB;
        while (ptr1 != ptr2)
        {
            if (ptr1 == NULL)
                ptr1 = headB;
            else
                ptr1 = ptr1->next;
            if (ptr2 == NULL)
                ptr2 = headA;
            else
                ptr2 = ptr2->next;
            if (ptr1 == NULL && ptr2 == NULL)
            {
                return NULL;
            }
        }
        return ptr1;
    }
};
