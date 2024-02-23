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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        //save the very first node
        ListNode *root = head;

        //count how many nodes in the linked list
        int n = 0;
        while(head){
            n++;
            head = head->next;
        }

        //part: how many nodes in a part
        //res: how many nodes should have part+1 nodes
        //times: how many nodes have been through
        //ans: where we store the final answer
        int part = n / k;
        int res = n % k;
        int times = 0;
        vector<ListNode*> ans;

        //Do k times
        for(int i = 0 ; i < k ; i++){
            //reset
            head = root;
            times = 0;
            //check if we have enough nodes in one linked list
            //if enough, we break
            while(head){
                if(res){
                    //if we still have res, the linked list we count now should have part+1 nodes
                    if(++times == part+1){
                        res--;
                        break;
                    }
                }else if(++times == part){
                    break;
                }
                head = head->next;
            }

            //push back the answer's root node and check if the head exists
            //if exists, let the root node to be the head->next node
            ans.push_back(root);
            if(head){
                root = head->next;
                head->next = NULL;
            }else{
                root = NULL;
            }
        }
        
        //return the answer
        return ans;
    }
};