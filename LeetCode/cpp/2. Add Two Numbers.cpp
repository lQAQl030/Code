/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    void addList(ListNode* l1, ListNode* l2){
        int sum = l1->val + l2->val;
        if(sum < 10){
            l1->val = sum;
        }else if(l1->next){
            l1->val = sum - 10;
            l1->next->val += 1;
        }else{
            l1->val = sum - 10;
            l1->next = new ListNode(1);
        }
        if(l1->next || l2->next){
            if(l1->next == nullptr) l1->next = new ListNode;
            if(l2->next == nullptr) l2->next = new ListNode;
        }else return;
        addList(l1->next, l2->next);
        return;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        addList(l1, l2);
        return l1;
    }
};