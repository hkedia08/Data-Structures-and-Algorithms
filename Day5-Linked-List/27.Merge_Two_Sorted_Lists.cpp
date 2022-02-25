// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *list = new ListNode(0);
        ListNode *head = list;
        ListNode *temp;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                list->next = list1;
                list = list1;
                temp = list1->next;
                list1->next = NULL;
                list1 = temp;
            }
            else
            {

                list->next = list2;
                list = list2;
                temp = list2->next;
                list2->next = NULL;
                list2 = temp;
            }
        }
        while (list1 != NULL)
        {
            list->next = list1;
            list = list1;
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            list->next = list2;
            list = list2;
            list2 = list2->next;
        }
        temp = head;
        return head->next;
        ListNode *list = new ListNode(0);
        ListNode *head = list;
        ListNode *temp;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                list->next = list1;
                list = list1;
                temp = list1->next;
                list1->next = NULL;
                list1 = temp;
            }
            else
            {

                list->next = list2;
                list = list2;
                temp = list2->next;
                list2->next = NULL;
                list2 = temp;
            }
        }
        while (list1 != NULL)
        {
            list->next = list1;
            list = list1;
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            list->next = list2;
            list = list2;
            list2 = list2->next;
        }
        temp = head;
        return head->next;
    }
};