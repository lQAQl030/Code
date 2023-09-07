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
    ListNode* reverseBetween(ListNode *head, int m, int n) {
        ListNode **prev = &head;
        for (int i=1; i<m; i++)
            prev = &(*prev)->next;
        ListNode *pivot = *prev;
        for (int i=m; i<n; i++) {
            swap(*prev, pivot->next->next);
            swap(*prev, pivot->next);
        }
        return head;
    }
};