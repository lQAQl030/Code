class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *p = head;
        if (p == NULL)
            return head;
        while (p->next)
        {
            if (p->val == p->next->val)
            {
                ListNode *temp = p->next;
                p->next = temp->next;
                delete temp;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};