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
    bool isPalindrome(ListNode* head) {
        if(!head->next) return true;
        vector<int> arr;
        while(head->next){
            arr.push_back(head->val);
            head = head->next;
        }
        arr.push_back(head->val);

        int i = 0, j = arr.size() - 1;
        while(i <= j){
            if(arr[i++] != arr[j--]) return false;
        }
        return true;
    }
};