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
    int max_diff = 0;

    void solve(TreeNode* root, int nmin, int nmax){
        if(!root) return;
        max_diff = max(max_diff, max(abs(nmin - root->val), abs(nmax - root->val)));
        nmin = min(nmin, root->val);
        nmax = max(nmax, root->val);
        solve(root->left, nmin, nmax);
        solve(root->right, nmin, nmax);
    }

    int maxAncestorDiff(TreeNode* root) {
        int nmin = root->val;
        int nmax = root->val;
        solve(root, nmin, nmax);
        return max_diff;
    }
};