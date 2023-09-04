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

    int solve(TreeNode* root, int depth){
        if(!root->left && !root->right) return depth+1;
        int x = 0, y = 0;
        if(root->left) x = solve(root->left, depth);
        if(root->right) y = solve(root->right, depth);
        if(x == 0) return y+1;
        if(y == 0) return x+1;
        return min(x,y)+1;
    }

    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return solve(root, 0);
    }
};