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
    void solve(ListNode* head, int &carry){
        if(!head) return;
        solve(head->next, carry);
        int product = head->val * 2 + carry;
        head->val = product % 10;
        carry = product / 10;
    }

    ListNode* doubleIt(ListNode* head) {
        int carry = 0;
        solve(head, carry);
        if(carry) head = new ListNode(carry, head);
        return head;
    }
};