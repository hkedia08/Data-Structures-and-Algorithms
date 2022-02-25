// https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution
{
public:
    int help(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int l = help(root->left);
        int r = help(root->right);
        return 1 + max(l, r);
    }
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int height = help(root);
        return height;
    }
};