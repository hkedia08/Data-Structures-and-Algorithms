//https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> level;
        if (root == NULL)
        {
            return level;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> res;
            int s = q.size();
            for (int i = 0; i < s; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                res.push_back(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            level.push_back(res);
        }
        return level;
    }
};
