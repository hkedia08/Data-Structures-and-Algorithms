//https://leetcode.com/problems/binary-tree-inorder-traversal/

class Solution
{
public:
    void intraversal(vector<int> &inorder, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        intraversal(inorder, root->left);
        inorder.push_back(root->val);
        intraversal(inorder, root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        intraversal(inorder, root);
        return inorder;
    }
};
