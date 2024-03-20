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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* tail2 = list2;
        while(tail2->next) tail2 = tail2->next;

        int count = 1;
        ListNode* cut1 = list1;
        while(count < a && cut1->next){
            cut1 = cut1->next;
            count++;
        }
        ListNode* rest1 = cut1;
        while(count < b+2 && rest1->next){
            rest1 = rest1->next;
            count++;
        }

        cut1->next = list2;
        tail2->next = rest1;

        return list1;
    }
};