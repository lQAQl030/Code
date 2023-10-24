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
    vector<int> v;
    void helper(TreeNode* root, int depth){
        if(depth == v.size()) v.push_back(-INT_MAX-1);
        v[depth] = max(root->val, v[depth]);
        if(root->left) helper(root->left, depth + 1);
        if(root->right) helper(root->right, depth + 1);
        return;
    }
    vector<int> largestValues(TreeNode* root) {
        if(!root) return v;
        helper(root, 0);
        return v;
    }
};