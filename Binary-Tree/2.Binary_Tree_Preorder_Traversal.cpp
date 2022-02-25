// https://leetcode.com/problems/binary-tree-preorder-traversal/

// recursive
class Solution
{
public:
    void preorder(vector<int> &result, TreeNode *root)
    {
        if (root == NULL)
            return;
        result.push_back(root->val);
        preorder(result, root->left);
        preorder(result, root->right);
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        preorder(result, root);
        return result;
    }
};
// iterative

class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        TreeNode *node = root;
        vector<int> preorder;
        stack<TreeNode *> s;
        while (true)
        {
            if (node != NULL)
            {
                s.push(node);
                preorder.push_back(node->val);
                node = node->left;
            }
            else
            {
                if (s.empty())
                    break;
                node = s.top();
                s.pop();
                node = node->right;
            }
        }
        return preorder;
    }
};