class Solution
{
public:
    vector<int> arr = {};
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (root)
        {
            inorderTraversal(root->left);
            arr.push_back(root->val);
            inorderTraversal(root->right);
        }
        return arr;
    }
};