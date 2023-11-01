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
    vector<int> ans;
    int max = INT_MIN, now = 0, freq = 0;

    void inorder(TreeNode* root){
        if(!root) return;
        if(root->left) inorder(root->left);

        if(root->val == now){
            freq++;
        }else{
            now = root->val;
            freq = 1;
        }
        if(freq > max){
            ans.clear();
            max = freq;
            ans.push_back(now);
        }else if(freq == max){
            ans.push_back(now);
        }
        
        if(root->right) inorder(root->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};