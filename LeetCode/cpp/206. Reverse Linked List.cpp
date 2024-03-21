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
    ListNode* reverseList(ListNode* head) {
        if(!head) return head;
        if(!head->next) return head;

        ListNode* prev = head;
        ListNode* next = NULL;
        head = head->next;
        prev->next = NULL;

        while(head->next){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        head->next = prev;
        
        return head;
    }
};