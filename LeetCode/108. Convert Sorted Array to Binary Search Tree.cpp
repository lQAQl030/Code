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

    TreeNode* solve(int begin, int end, vector<int>& nums){
        if(begin >= end) return nullptr;

        int mid = (begin+end)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = solve(begin, mid, nums);
        root->right = solve(mid+1, end, nums);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0, nums.size(), nums);
    }
};