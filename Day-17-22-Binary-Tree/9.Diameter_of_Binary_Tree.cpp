// https://leetcode.com/problems/diameter-of-binary-tree/

class Solution
{
public:
    int help(TreeNode *root, int &diameter)
    {
        if (root == NULL)
            return 0;
        int l = help(root->left, diameter);
        int r = help(root->right, diameter);
        diameter = max(diameter, l + r);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        help(root, diameter);
        return diameter;
    }
};