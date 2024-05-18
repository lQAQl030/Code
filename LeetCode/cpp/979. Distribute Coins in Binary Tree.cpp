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
    int total = 0;

    int solve(TreeNode* root){
        if(!root) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        total += abs(left) + abs(right);
        return left + right + root->val - 1;;
    }
    
    int distributeCoins(TreeNode* root) {
        solve(root);
        return total;
    }
};