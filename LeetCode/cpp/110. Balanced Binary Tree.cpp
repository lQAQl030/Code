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

    int solve(TreeNode *root, int depth){
        if(!root->left && !root->right) return depth+1;
        int x = 0, y = 0;
        if(root->left) x = solve(root->left, depth);
        if(root->right) y = solve(root->right, depth);
        if(abs(x-y) > 1 || x == INT_MAX || y == INT_MAX) return INT_MAX;
        else return max(x,y)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        return solve(root, 0) != INT_MAX;
    }
};