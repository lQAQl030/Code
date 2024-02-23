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
    map<int,int> mp;

    void solve(TreeNode* root, int &sum){
        mp[root->val]++;

        if(!root->left && !root->right){
            int odd = 0, even = 0;
            for(auto &[key, value] : mp){
                if(value % 2 == 0) even++;
                else odd++;
                if(odd > 1) return;
            }
            sum++;
            return;
        }
        
        if(root->left){
            solve(root->left, sum);
            mp[root->left->val]--;
        }
        if(root->right){
            solve(root->right, sum);
            mp[root->right->val]--;
        }

        return;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int sum = 0;
        solve(root, sum);
        return sum;
    }
};