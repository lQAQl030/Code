/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *rootA = headA, *rootB = headB;
        int a = 0, b = 0;
        while(headA){
            a++;
            headA = headA->next;
        }
        while(headB){
            b++;
            headB = headB->next;
        }

        int diff = abs(a-b);
        headA = rootA;
        headB = rootB;
        if(a > b){
            for(int i = 0 ; i < diff ; i++){
                headA = headA->next;
            }
        }else{
            for(int i = 0 ; i < diff ; i++){
                headB = headB->next;
            }
        }

        while(headA){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};