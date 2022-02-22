// https://leetcode.com/problems/balanced-binary-tree/

class Solution
{
public:
    int help(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = help(root->left);
        if (l == -1)
            return -1;
        int r = help(root->right);
        if (r == -1)
            return -1;
        if (abs(l - r) > 1)
            return -1;
        return 1 + max(l, r);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int res = help(root);
        return res != -1;
    }
};