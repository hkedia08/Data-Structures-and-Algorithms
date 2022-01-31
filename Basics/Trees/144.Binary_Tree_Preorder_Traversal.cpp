//https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution
{
public:
    void preorder(vector<int> &pre, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        pre.push_back(root->val);
        preorder(pre, root->left);
        preorder(pre, root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> pre;
        preorder(pre, root);
        return pre;
    }
};