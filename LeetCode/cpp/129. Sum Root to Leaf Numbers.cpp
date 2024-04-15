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
    int sub = 0;

    int sumNumbers(TreeNode* root) {
        sub = sub*10 + root->val;
        if(!root->left && !root->right) return sub;

        int sum = 0;
        if(root->left){
            sum += sumNumbers(root->left);
            sub /= 10;
        }
        if(root->right){
            sum += sumNumbers(root->right);
            sub /= 10;
        }
        return sum;
    }
};