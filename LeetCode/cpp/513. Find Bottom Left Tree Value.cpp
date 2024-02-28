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
    void solve(TreeNode* root, int depth, int &ans, int &max){
        if(!root->left && !root->right){
            if(depth > max){
                ans = root->val;
                max = depth;
            }
            return;
        }
        if(root->left) solve(root->left, depth+1, ans, max);
        if(root->right) solve(root->right, depth+1, ans, max);
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        int ans = -1;
        int max = -1;
        solve(root, 0, ans, max);
        return ans;
    }
};