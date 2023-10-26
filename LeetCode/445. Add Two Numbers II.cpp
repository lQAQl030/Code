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
    int count = 0, count1 = 0;

    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode *prev = NULL, *next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head = prev;
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* rl1 = reverseList(l1);
        count1 = count;
        count = 0;
        ListNode* rl2 = reverseList(l2);
        if(count > count1) swap(rl1,rl2);
        l1 = rl1; l2 = rl2;
        while(rl1){
            if(rl2) rl1->val += rl2->val;
            if(rl1->val > 9){
                rl1->val -= 10;
                if(!rl1->next){
                    rl1->next = new ListNode;
                }
                rl1->next->val += 1;
            }
            rl1 = rl1->next;
            if(rl2) rl2 = rl2->next;
        }
        return reverseList(l1);
    }
};