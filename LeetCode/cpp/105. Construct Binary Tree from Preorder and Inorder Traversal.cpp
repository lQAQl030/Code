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
    int flow = 0, i = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int val = INT_MAX) {
        if(flow >= preorder.size()) return NULL;
        if(inorder[i] == val){
            i++;
            return NULL;
        }
        TreeNode *head = new TreeNode(preorder[flow++]);
        head->left = buildTree(preorder, inorder, head->val);
        head->right = buildTree(preorder, inorder, val);
        return head;
    }
};