/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int flow, i, track;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int val){
        if(flow < 0) return NULL;
        if(inorder[i] == val || (track+1 < postorder.size() && inorder[i] == postorder[track+1])){
            i--;
            track++;
            return NULL;
        }
        TreeNode *head = new TreeNode(postorder[flow--]);
        track--;
        head->right = build(inorder, postorder, head->val);
        head->left = build(inorder, postorder, val);
        return head;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        flow = i = track = postorder.size()-1;
        return build(inorder, postorder, INT_MAX);
    }
};