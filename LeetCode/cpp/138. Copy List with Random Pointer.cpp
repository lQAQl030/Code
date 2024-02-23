/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //return NULL if no node exists
        if(!head) return NULL;

        //make a new linked list head named root
        Node *root = new Node(head->val);

        //store the head of both linked list
        Node *present = root, *origin = head;

        //make two vectors to store all the nodes from both list
        vector<Node*> prev, now;
        prev.push_back(head);
        now.push_back(root);

        //make the new linked list and store nodes in prev and now
        while(head->next){
            root->next = new Node(head->next->val);
            head = head->next;
            root = root->next;
            prev.push_back(head);
            now.push_back(root);
        }

        //reset the head node for both linked list
        head = origin;
        root = present;

        //let new linked list have the same random as the old one
        while(head){
            if(head->random){
                vector<Node*>::iterator it = find(prev.begin(), prev.end(), head->random);
                root->random = now[distance(prev.begin(), it)];
            }else{
                root->random = NULL;
            }
            head = head->next;
            root = root->next;
        }

        //return the new linked list head
        return present;
    }
};