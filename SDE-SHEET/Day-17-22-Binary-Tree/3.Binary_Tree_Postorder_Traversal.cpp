// https://leetcode.com/problems/binary-tree-postorder-traversal/

// recursive

class Solution
{
public:
    void postorder(vector<int> &result, TreeNode *root)
    {
        if (root == NULL)
            return;
        postorder(result, root->left);
        postorder(result, root->right);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        postorder(result, root);
        return result;
    }
};

// iterative
// two stack solution
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> postorder;
        if (root == NULL)
        {
            return postorder;
        }
        TreeNode *node;
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty())
        {
            node = s1.top();
            s2.push(s1.top());
            s1.pop();
            if (node->left != NULL)
                s1.push(node->left);
            if (node->right != NULL)
                s1.push(node->right);
        }
        while (!s2.empty())
        {
            postorder.push_back(s2.top()->val);
            s2.pop();
        }
        return postorder;
    }
};