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

    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int val){
        if(flow >= preorder.size()) return NULL;
        if(inorder[i] == val){
            i++;
            return NULL;
        }
        TreeNode *head = new TreeNode(preorder[flow++]);
        head->left = build(preorder, inorder, head->val);
        head->right = build(preorder, inorder, val);
        return head;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, INT_MAX);
    }
};