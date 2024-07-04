class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* root = head, *node = head, *now = head;

        while(now->next){
            ListNode* sum = now;
            now = now->next;
            while(now->val != 0){
                sum->val += now->val;
                now = now->next;
            }
            node->next = sum;
            node = node->next;
            node->next = NULL;
        }
        return root;
    }
};