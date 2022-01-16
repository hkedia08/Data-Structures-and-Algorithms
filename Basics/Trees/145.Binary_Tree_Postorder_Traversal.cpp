//https://leetcode.com/problems/binary-tree-postorder-traversal/
class Solution
{
public:
    void postorder(vector<int> &post, TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        postorder(post, root->left);
        postorder(post, root->right);
        post.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> post;
        postorder(post, root);
        return post;
    }
};
