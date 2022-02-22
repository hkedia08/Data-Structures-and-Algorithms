// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1/#

class Solution
{
public:
    int help(TreeNode *root, int &pathsum)
    {
        if (root == NULL)
            return 0;
        int l = max(0, help(root->left, pathsum));
        int r = max(0, help(root->right, pathsum));
        pathsum = max(pathsum, l + r + root->val);
        return (root->val) + max(l, r);
    }
    int maxPathSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int pathsum = INT_MIN;
        help(root, pathsum);
        return pathsum;
    }
};