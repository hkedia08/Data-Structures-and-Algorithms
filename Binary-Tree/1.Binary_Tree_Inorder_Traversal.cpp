// https://leetcode.com/problems/binary-tree-inorder-traversal/

// recursive
class Solution
{
public:
    void inorder(vector<int> &result, TreeNode *root)
    {
        if (root == NULL)
            return;
        inorder(result, root->left);
        result.push_back(root->val);
        inorder(result, root->right);
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        inorder(result, root);
        return result;
    }
};

// iterative

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *node = root;
        vector<int> inorder;
        stack<TreeNode *> s;
        while (true)
        {
            if (node != NULL)
            {
                s.push(node);
                node = node->left;
            }
            else
            {
                if (s.empty())
                    break;
                node = s.top();
                s.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};