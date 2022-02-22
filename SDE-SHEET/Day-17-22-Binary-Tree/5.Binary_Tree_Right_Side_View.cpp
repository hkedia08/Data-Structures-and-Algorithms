// https://leetcode.com/problems/binary-tree-right-side-view/
class Solution
{
public:
    void help(vector<int> &result, TreeNode *root, int level)
    {
        if (root == NULL)
        {
            return;
        }
        if (level == result.size())
            result.push_back(root->val);
        if (root->right != NULL)
            help(result, root->right, level + 1);
        if (root->left != NULL)
            help(result, root->left, level + 1);
    }
    vector<int> rightSideView(TreeNode *root)
    {
        int level = 0;
        vector<int> result;
        help(result, root, level);
        return result;
    }
};