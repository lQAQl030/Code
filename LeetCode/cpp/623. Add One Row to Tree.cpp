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
    void helper(TreeNode* root, int &val, int depth){
        if(depth > 2){
            if(root->left) helper(root->left, val, depth-1);
            if(root->right) helper(root->right, val, depth-1);
        }else{
            root->left = new TreeNode(val, root->left, NULL);
            root->right = new TreeNode(val, NULL, root->right);
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) return new TreeNode(val, root, NULL);

        helper(root, val, depth);
        return root;
    }
};