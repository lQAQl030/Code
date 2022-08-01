class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL || q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left == NULL || root->right == NULL)
            return false;
        return isSameTree(root->left, root->right);
    }
};