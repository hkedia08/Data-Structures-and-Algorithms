// https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> q;
        if (root == NULL)
            return ans;
        q.push(root);
        while (!q.empty())
        {
            int siz = q.size();
            vector<int> level;
            for (int i = 0; i < siz; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            // for a particular level
            ans.push_back(level);
        }
        return ans;
    }
};